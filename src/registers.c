#include "registers.h"
#include <stddef.h>

static int accumulator = 0;
static int icounter = 0;
static int flags = 0;

int sc_regInit(void) {
    flags = 0;
    return 0;
}

int sc_regSet(int reg, int value) {
    if (reg != FLAG_Z && reg != FLAG_S) {
        return -1;
    }
    if (value == 0) {
        flags &= ~reg;
    } else {
        flags |= reg;
    }
    return 0;
}

int sc_regGet(int reg, int* value) {
    if ((reg != FLAG_Z && reg != FLAG_S) || value == NULL) {
        return -1;
    }
    *value = (flags & reg) ? 1 : 0;
    return 0;
}

int sc_accumulatorInit(void) {
    accumulator = 0;
    return 0;
}

int sc_accumulatorSet(int value) {
    if (value < -32768 || value > 32767) {
        return -1;
    }
    accumulator = value;
    return 0;
}

int sc_accumulatorGet(int* value) {
    if (value == NULL) {
        return -1;
    }
    *value = accumulator;
    return 0;
}

int sc_icounterInit(void) {
    icounter = 0;
    return 0;
}

int sc_icounterSet(int value) {
    icounter = value;
    return 0;
}

int sc_icounterGet(int* value) {
    if (value == NULL) {
        return -1;
    }
    *value = icounter;
    return 0;
}