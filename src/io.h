#ifndef IO_H
#define IO_H
#include <stddef.h>
#include "myTerm.h"

void printCell(int address, enum colors fg, enum colors bg);
void printFlags(void);
void printDecodedCommand(int value);
void printAccumulator(void);
void printCounters(void);

#endif // IO_H