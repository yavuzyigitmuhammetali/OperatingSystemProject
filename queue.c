#include "queue.h"
#include <stdio.h>

// Function to initialize a queue
void initQueue(Queue *q) {
    q->front = q->rear = -1; // Initialize front and rear pointers to -1 indicating empty queue
}

// Function to check if a queue is empty
int isEmpty(Queue *q) {
    return q->front == -1; // If front is -1, queue is empty
}

// Function to enqueue a process into the queue
void enqueue(Queue *q, Process *p) {
    if (q->rear == MAX_PROCESSES - 1) { // If rear is at the end of the array
        printf("Queue is full\n"); // Print message and return if queue is full
        return;
    }
    if (isEmpty(q)) { // If queue is empty
        q->front = q->rear = 0; // Set both front and rear to 0
    } else {
        q->rear++; // Increment rear pointer
    }
    q->arr[q->rear] = p; // Add the process to the queue
}

// Function to dequeue a process from the queue
Process *dequeue(Queue *q) {
    if (isEmpty(q)) { // If queue is empty
        printf("Queue is empty\n"); // Print message and return NULL
        return NULL;
    }
    Process *p = q->arr[q->front]; // Get the process at the front of the queue
    if (q->front == q->rear) { // If only one element in the queue
        q->front = q->rear = -1; // Reset front and rear to -1 to indicate empty queue
    } else {
        q->front++; // Increment front pointer
    }
    return p; // Return the dequeued process
}
