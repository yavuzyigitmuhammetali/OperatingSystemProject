#include "utils.h"  // Includes the header file for utility functions
#include <stdio.h>  // Includes the standard input/output library
#include <stdlib.h>  // Includes the standard library for memory allocation

// Function to create an input file if it doesn't exist
void createInputFileIfNotExists(const char *filename) {
    FILE *file = fopen(filename, "r");  // Tries to open the file for reading
    if (file == NULL) {  // Checks if the file does not exist
        file = fopen(filename, "w");  // Creates the file for writing
        if (file != NULL) {  // Checks if the file creation is successful
            // Writes default process information to the file
            fprintf(file, "P1,0,0,20,100,50\nP2,2,1,15,200,30\nP3,4,2,10,150,20\nP4,6,3,30,300,40\n");
            fclose(file);  // Closes the file
        }
    } else {
        fclose(file);  // Closes the file if it already exists
    }
}

// Function to allocate RAM to a process
void allocateRAM(Process *p, int *ram_available) {
    if (*ram_available >= p->ram_required) {  // Checks if there is enough available RAM
        *ram_available -= p->ram_required;  // Updates the available RAM
        // Prints allocation information
        printf("Allocated %d RAM to process %s. Remaining RAM: %d\n", p->ram_required, p->name, *ram_available);
    } else {
        printf("Not enough RAM for process %s\n", p->name);  // Prints error message if there's not enough RAM
    }
}

// Function to execute a process for a given quantum
void executeProcess(Process *p, int quantum) {
    if (p->remaining_time > quantum) {  // Checks if the process has remaining time greater than the quantum
        p->remaining_time -= quantum;  // Reduces the remaining time of the process
        // Prints execution information
        printf("Process %s executed for %d units. Remaining time: %d\n", p->name, quantum, p->remaining_time);
    } else {
        printf("Process %s completed execution\n", p->name);  // Prints completion message if the process finishes execution
        p->remaining_time = 0;  // Sets remaining time to 0
    }
}
