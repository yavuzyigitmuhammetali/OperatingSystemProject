#ifndef UTILS_H
#define UTILS_H

#include "process.h"

void allocateRAM(Process *p, int *ram_available);

void executeProcess(Process *p, int quantum_time);

void createInputFileIfNotExists(const char *filename);

#endif //UTILS_H