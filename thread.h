/*
 * Thread.h
 *
 *  Created on: 23.01.2014
 *  Author: johannes
 */

#ifndef THREAD_H_
#define THREAD_H_

#define THREAD_INVALID_ID -1
#define THREAD_READY 1
#define THREAD_UNUSED 2
#define THREAD_RUNNING 3

#include <setjmp.h>

typedef int ThreadId;
typedef int ThreadState;

typedef void* (*ThreadFunc)(void*);

typedef struct Thread {
	int ID;
	int state;
	ThreadFunc func;
	jmp_buf context;
} thread_t;

#endif /* THREAD_H_ */
