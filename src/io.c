#include "io.h"
#include "commands.h"
#include "memory.h"
#include "registers.h"
#include "myTerm.h"
#include "myBigChars.h"
#include <stddef.h>
#include <stdio.h>

void printCell(int address, enum colors fg, enum colors bg) {
    int val = 0;
    if (sc_memoryGet(address, &val)) {
        printf("Invalid address: %d\n", address);
        return;
    }
    mt_gotoXY(address % 10 * 5, address / 10 + 2);
    mt_setfgcolor(fg);
    mt_setbgcolor(bg);
    printf("%04X", val);
    mt_setdefaultcolor();
}

void printFlags(void) {
    int fz, fs;
    sc_regGet(FLAG_Z, &fz);
    sc_regGet(FLAG_S, &fs);

    mt_gotoXY(50, 2);
    printf("Flags: ");
    if (fz) printf("Z ");
    if (fs) printf("S ");
    printf("\n");
}

void printDecodedCommand(int value) {
    mt_gotoXY(50, 4);
    printf("Decoded Command:\n");
    mt_gotoXY(50, 5);
    printf("  Decimal: %d\n", value);
    mt_gotoXY(50, 6);
    printf("  Octal: %o\n", value);
    mt_gotoXY(50, 7);
    printf("  Hex: %X\n", value);
    mt_gotoXY(50, 8);
    printf("  Binary: ");
    for (int i = 15; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
    }
    printf("\n");
}

void printAccumulator(void) {
    int val;
    if (sc_accumulatorGet(&val) == 0) {
        mt_gotoXY(50, 10);
        printf("Accumulator: %d\n", val);
    } else {
        mt_gotoXY(50, 10);
        printf("Error: accumulator get\n");
    }
}

void printCounters(void) {
    int val;
    if (sc_icounterGet(&val) == 0) {
        mt_gotoXY(50, 12);
        printf("ICounter: %d\n", val);
    } else {
        mt_gotoXY(50, 12);
        printf("Error: icounter get\n");
    }
}

void printBigCell(int address, enum colors fg, enum colors bg) {
    int val;
    if (sc_memoryGet(address, &val)) {
        printf("Invalid address: %d\n", address);
        return;
    }

    int big[2] = {0};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            bc_setbigcharpos(big, i, j, (val >> (i * 8 + j)) & 1);
        }
    }

    bc_printbigchar(big, 10, 40, fg, bg);
}