#ifndef PROCESS_H
#define PROCESS_H

// Define process structure
typedef struct {
    char name[10];
    int arrival_time;
    int priority;
    int burst_time;
    int ram_required;
    int cpu_percentage;
    int remaining_time;
} Process;

#endif //PROCESS_H