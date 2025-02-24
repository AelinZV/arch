#ifndef MYTERM_H
#define MYTERM_H

#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>

enum colors {
    BLACK = 0,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
};

int mt_clrscr(void);
int mt_gotoXY(int x, int y);
int mt_getscreensize(int *rows, int *cols);
int mt_setfgcolor(enum colors color);
int mt_setbgcolor(enum colors color);
int mt_setdefaultcolor(void);
int mt_setcursorvisible(int value);
int mt_delline(void);

#endif // MYTERM_H