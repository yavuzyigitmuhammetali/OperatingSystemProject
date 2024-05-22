#ifndef QUEUE_H
#define QUEUE_H

#include "process.h"

typedef struct {
    Process *processes[MAX_PROCESSES];
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue *q);
void enqueue(Queue *q, Process *p);
Process* dequeue(Queue *q);
int isQueueEmpty(Queue *q);

#endif
