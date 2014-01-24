/*
 * scheduler.c
 *
 *  Created on: 23.01.2014
 *      Author: johannes
 */

#include <stdlib.h>
#include <msp430.h>

#include "thread.h"
#include "scheduler.h"

thread_t threads[MAX_THREADS];
int currentId = -1;

int next_id = 0;

ThreadId createThread(ThreadFunc func) {
	int x = next_id;
	threads[next_id].ID = next_id;
	threads[next_id].state = THREAD_READY;
	threads[next_id].func = func;

	next_id += 1;
	return x;
}

void cleanUp(ThreadId th) {
	threads[th].state = THREAD_UNUSED;
	threads[th].func = NULL;
}

ThreadId findNextReady() {
	int x = 0;
	while (threads[x].state != THREAD_READY) {
		++x;
		if (x >= MAX_THREADS) {
			return THREAD_INVALID_ID;
		}
	}

	return x;
}

void switchTo(ThreadId th) {
	currentId = th;
	threads[th].state = THREAD_RUNNING;

	longjmp(threads[th].context, 1);
}

ThreadId schedulerStartThread(ThreadFunc func) {
	ATOMIC_START;

	ThreadId th = createThread(func);

	if (0 == setjmp(threads[th].context)) {
		ATOMIC_STOP;

		return th;
	} else {
		_set_SP_register(START_ADDRESS - th * STACK_SIZE_PER_THREAD);
		ATOMIC_STOP;

		currentId = th;
		threads[th].func(0);
		cleanUp(th);

		return THREAD_INVALID_ID;
	}
}

ThreadId schedulerNextThread() {
	ATOMIC_START;

	ThreadId th = findNextReady();
	if (THREAD_INVALID_ID != th) {

		if (THREAD_INVALID_ID != currentId) {

			if (0 == setjmp(threads[currentId].context)) {
				threads[currentId].state = THREAD_READY;
				switchTo(th);
			}
		} else {
			switchTo(th);
		}
	}
	ATOMIC_STOP;
	return THREAD_INVALID_ID;
}
