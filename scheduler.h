/*
 * scheduler.h
 *
 *  Created on: 23.01.2014
 *      Author: johannes
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "thread.h"

#define MAX_THREADS 5
#define STACK_SIZE_PER_THREAD 32
#define START_ADDRESS 0x3FF
// disable interupt
#define ATOMIC_START _DINT()
// enable interupt
#define ATOMIC_STOP _EINT()

ThreadId schedulerStartThread(ThreadFunc func);
ThreadId schedulerNextThread();

#endif /* SCHEDULER_H_ */
