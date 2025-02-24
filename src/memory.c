#include "memory.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static int memory[MEMORY_SIZE];

int sc_memoryInit(void) {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        memory[i] = 0;
    }
    return 0;
}

int sc_memorySet(int address, int value) {
    if (address < 0 || address >= MEMORY_SIZE || value < -32768 || value > 32767) {
        return -1;
    }
    memory[address] = value;
    return 0;
}

int sc_memoryGet(int address, int* value) {
    if (address < 0 || address >= MEMORY_SIZE || value == NULL) {
        return -1;
    }
    *value = memory[address];
    return 0;
}

int sc_memorySave(const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        return -1;
    }
    fwrite(memory, sizeof(int), MEMORY_SIZE, file);
    fclose(file);
    return 0;
}

int sc_memoryLoad(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return -1;
    }
    fread(memory, sizeof(int), MEMORY_SIZE, file);
    fclose(file);
    return 0;
}