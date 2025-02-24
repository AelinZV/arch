#ifndef REGISTERS_H
#define REGISTERS_H

#define FLAG_Z (1 << 0)
#define FLAG_S (1 << 1)

int sc_regInit(void);
int sc_regSet(int reg, int value);
int sc_regGet(int reg, int* value);

int sc_accumulatorInit(void);
int sc_accumulatorSet(int value);
int sc_accumulatorGet(int* value);

int sc_icounterInit(void);
int sc_icounterSet(int value);
int sc_icounterGet(int* value);

#endif // REGISTERS_H