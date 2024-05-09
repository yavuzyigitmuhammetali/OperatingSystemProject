#include "utils.h"
#include <stdio.h>

void allocateRAM(Process *p, int *ram_available) {
    if (*ram_available >= p->ram_required) {
        *ram_available -= p->ram_required;
        printf("Process %s allocated %d MB RAM\n", p->name, p->ram_required);
    } else {
        printf("Insufficient RAM for process %s\n", p->name);
    }
}

void executeProcess(Process *p, int quantum_time) {
    int time_remaining = p->remaining_time;
    if (time_remaining <= quantum_time) {
        printf("Process %s ran for %d seconds\n", p->name, time_remaining);
        p->remaining_time = 0;
    } else {
        printf("Process %s ran for %d seconds\n", p->name, quantum_time);
        p->remaining_time -= quantum_time;
    }
}

void createInputFileIfNotExists(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        file = fopen(filename, "w");
        fclose(file);
        printf("Created %s\n", filename);
    } else {
        fclose(file);
    }
}