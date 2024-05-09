#include "utils.h"
#include <stdio.h>

// Function to allocate RAM for a process
void allocateRAM(Process *p, int *ram_available) {
    if (*ram_available >= p->ram_required) { // Check if there is enough RAM available
        *ram_available -= p->ram_required; // Deduct RAM required by the process from available RAM
        printf("Process %s allocated %d MB RAM\n", p->name, p->ram_required); // Print allocation message
    } else {
        printf("Insufficient RAM for process %s\n", p->name); // Print error message if insufficient RAM
    }
}

// Function to execute a process for a given quantum time
void executeProcess(Process *p, int quantum_time) {
    int time_remaining = p->remaining_time;
    if (time_remaining <= quantum_time) { // If remaining time is less than or equal to quantum time
        printf("Process %s ran for %d seconds\n", p->name, time_remaining); // Run process for remaining time
        p->remaining_time = 0; // Set remaining time to 0
    } else {
        printf("Process %s ran for %d seconds\n", p->name, quantum_time); // Run process for quantum time
        p->remaining_time -= quantum_time; // Deduct quantum time from remaining time
    }
}

// Function to create an input file if it doesn't exist
void createInputFileIfNotExists(const char *filename) {
    FILE *file = fopen(filename, "r"); // Try to open file for reading
    if (file == NULL) { // If file does not exist
        file = fopen(filename, "w"); // Create file for writing
        fclose(file); // Close the file
        printf("Created %s\n", filename); // Print message indicating file creation
    } else {
        fclose(file); // Close the file if it exists
    }
}
