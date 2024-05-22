#ifndef UTILS_H
#define UTILS_H

#include "process.h"

void createInputFileIfNotExists(const char *filename);
void allocateRAM(Process *p, int *ram_available);
void executeProcess(Process *p, int quantum);

#endif
