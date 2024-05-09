#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process.h"
#include "queue.h"
#include "utils.h"
#define RAM_SIZE 2048

int main() {
    createInputFileIfNotExists("input.txt");

    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    Queue priority1_queue, priority2_queue, priority3_queue;
    initQueue(&priority1_queue);
    initQueue(&priority2_queue);
    initQueue(&priority3_queue);

    int ram_available = RAM_SIZE;

    char queue1_names[MAX_PROCESSES][10] = {0};
    char queue2_names[MAX_PROCESSES][10] = {0};
    char queue3_names[MAX_PROCESSES][10] = {0};

    int queue1_count = 0, queue2_count = 0, queue3_count = 0;

    char line[100];
    while (fgets(line, sizeof(line), input_file)) {
        Process *p = malloc(sizeof(Process));
        sscanf(line, "%[^,],%d,%d,%d,%d,%d", p->name, &p->arrival_time, &p->priority, &p->burst_time, &p->ram_required, &p->cpu_percentage);
        p->remaining_time = p->burst_time;

        if (p->priority == 0) {
            allocateRAM(p, &ram_available);
        }

        if (p->priority == 0) {
            printf("Process %s queued to be assigned to CPU-1\n", p->name);
            printf("Process %s assigned to CPU-1\n", p->name);
            executeProcess(p, p->burst_time);
            printf("Process %s completed and terminated\n", p->name);
        } else {
            if (p->priority == 1) {
                printf("Process %s placed in que1 queue to be assigned to CPU-2\n", p->name);
                enqueue(&priority1_queue, p);
                strcpy(queue1_names[queue1_count++], p->name);
            } else if (p->priority == 2) {
                printf("Process %s placed in que2 queue to be assigned to CPU-2\n", p->name);
                enqueue(&priority2_queue, p);
                strcpy(queue2_names[queue2_count++], p->name);
            } else if (p->priority == 3) {
                printf("Process %s placed in que3 queue to be assigned to CPU-2\n", p->name);
                enqueue(&priority3_queue, p);
                strcpy(queue3_names[queue3_count++], p->name);
            }
        }
    }

    printf("CPU-1 que1(priority-0) (FCFS)→");
    for (int i = 0; i < queue1_count; i++) {
        printf("%s-", queue1_names[i]);
    }
    printf("\n");

    printf("CPU-2 que2(priority-1) (SJF)→");
    for (int i = 0; i < queue2_count; i++) {
        printf("%s-", queue2_names[i]);
    }
    printf("\n");

    printf("CPU-2 que3(priority-2) (RR-q8)→");
    for (int i = 0; i < queue3_count; i++) {
        printf("%s-", queue3_names[i]);
    }
    printf("\n");

    fclose(input_file);

    return 0;
}
