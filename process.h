#ifndef PROCESS_H
#define PROCESS_H

#define MAX_PROCESSES 100

typedef struct {
    char name[10];
    int arrival_time;
    int priority;
    int burst_time;
    int remaining_time;
    int ram_required;
    int cpu_percentage;
} Process;

#endif
