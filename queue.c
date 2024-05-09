// queue.c
#include "queue.h"
#include <stdio.h>

void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, Process *p) {
    if (q->rear == MAX_PROCESSES - 1) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->arr[q->rear] = p;
}

Process *dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return NULL;
    }
    Process *p = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return p;
}