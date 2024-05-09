#ifndef QUEUE_H
#define QUEUE_H

#include "process.h"

#define MAX_PROCESSES 100

// Define queue structure
typedef struct {
    Process *arr[MAX_PROCESSES];
    int front, rear;
} Queue;

//test
void initQueue(Queue *q);

int isEmpty(Queue *q);

void enqueue(Queue *q, Process *p);

Process *dequeue(Queue *q);

#endif //QUEUE_H