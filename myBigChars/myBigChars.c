#include "myBigChars.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int bc_strlen(char *str) {
    if (!str) return 0;
    int len = 0;
    while (*str) {
        if ((*str & 0xC0) != 0x80) len++;
        str++;
    }
    return len;
}

int bc_printA(char *str) {
    if (!str) return -1;
    printf("\033(0%s\033(B", str);
    return 0;
}

int bc_box(int x1, int y1, int x2, int y2, enum colors box_fg, enum colors box_bg, char *header, enum colors header_fg, enum colors header_bg) {
    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) return -1;

    mt_setfgcolor(box_fg);
    mt_setbgcolor(box_bg);

    for (int i = 0; i < x2; i++) {
        for (int j = 0; j < y2; j++) {
            mt_gotoXY(x1 + i, y1 + j);
            if (i == 0 || i == x2 - 1 || j == 0 || j == y2 - 1) {
                printf("x");
            } else {
                printf(" ");
            }
        }
    }

    if (header) {
        int header_len = bc_strlen(header);
        int header_x = x1 + (x2 - header_len) / 2;
        int header_y = y1 + 1;
        mt_gotoXY(header_x, header_y);
        mt_setfgcolor(header_fg);
        mt_setbgcolor(header_bg);
        printf("%s", header);
    }

    mt_setdefaultcolor();
    return 0;
}

int bc_setbigcharpos(int *big, int x, int y, int value) {
    if (x < 0 || x >= BC_SIZE || y < 0 || y >= BC_SIZE) return -1;
    int index = x / 4;
    int bit = (x % 4) * 8 + y;
    if (value) {
        big[index] |= (1 << bit);
    } else {
        big[index] &= ~(1 << bit);
    }
    return 0;
}

int bc_getbigcharpos(int *big, int x, int y, int *value) {
    if (x < 0 || x >= BC_SIZE || y < 0 || y >= BC_SIZE || !value) return -1;
    int index = x / 4;
    int bit = (x % 4) * 8 + y;
    *value = (big[index] >> bit) & 1;
    return 0;
}

int bc_printbigchar(int big[2], int x, int y, enum colors fg, enum colors bg) {
    for (int i = 0; i < BC_SIZE; i++) {
        for (int j = 0; j < BC_SIZE; j++) {
            int value;
            bc_getbigcharpos(big, i, j, &value);
            mt_gotoXY(x + i, y + j);
            mt_setfgcolor(fg);
            mt_setbgcolor(bg);
            printf(value ? "a" : " ");
        }
    }
    mt_setdefaultcolor();
    return 0;
}

int bc_bigcharwrite(int fd, int *big, int count) {
    if (fd < 0 || !big || count <= 0) return -1;
    return write(fd, big, count * sizeof(int) * 2) == count * sizeof(int) * 2 ? 0 : -1;
}

int bc_bigcharread(int fd, int *big, int need_count, int *count) {
    if (fd < 0 || !big || need_count <= 0 || !count) return -1;
    *count = read(fd, big, need_count * sizeof(int) * 2) / (sizeof(int) * 2);
    return *count > 0 ? 0 : -1;
}