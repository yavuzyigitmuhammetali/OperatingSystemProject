#include "queue.h"  // Includes the header file for queue-related structures and definitions
#include <stddef.h>  // Includes the header file for NULL definition

// Function to initialize a queue
void initQueue(Queue *q) {
    q->front = 0;    // Initializes front of the queue
    q->rear = -1;    // Initializes rear of the queue
    q->size = 0;     // Initializes size of the queue
}

// Function to enqueue a process into the queue
void enqueue(Queue *q, Process *p) {
    if (q->size < MAX_PROCESSES) {  // Checks if the queue is not full
        q->rear = (q->rear + 1) % MAX_PROCESSES;  // Updates rear index
        q->processes[q->rear] = p;  // Adds the process to the queue
        q->size++;  // Increases the size of the queue
    }
}

// Function to dequeue a process from the queue
Process* dequeue(Queue *q) {
    if (q->size > 0) {  // Checks if the queue is not empty
        Process *p = q->processes[q->front];  // Retrieves the process from the front of the queue
        q->front = (q->front + 1) % MAX_PROCESSES;  // Updates front index
        q->size--;  // Decreases the size of the queue
        return p;  // Returns the dequeued process
    }
    return NULL;  // Returns NULL if the queue is empty
}

// Function to check if the queue is empty
int isQueueEmpty(Queue *q) {
    return q->size == 0;  // Returns 1 if the queue is empty, otherwise returns 0
}
