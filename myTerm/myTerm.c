#include "myTerm.h"
#include <unistd.h>
#include <sys/ioctl.h>

int mt_clrscr(void) {
    if (write(STDOUT_FILENO, "\033[2J", 4) == -1) {
        return -1;
    }
    if (write(STDOUT_FILENO, "\033[H", 3) == -1) {
        return -1;
    }
    return 0;
}

int mt_gotoXY(int x, int y) {
    char buf[32];
    int len = snprintf(buf, sizeof(buf), "\033[%d;%dH", y, x);
    if (write(STDOUT_FILENO, buf, len) == -1) {
        return -1;
    }
    return 0;
}

int mt_getscreensize(int *rows, int *cols) {
    struct winsize ws;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1) {
        return -1;
    }
    *rows = ws.ws_row;
    *cols = ws.ws_col;
    return 0;
}

int mt_setfgcolor(enum colors color) {
    char buf[16];
    int len = snprintf(buf, sizeof(buf), "\033[3%dm", color);
    if (write(STDOUT_FILENO, buf, len) == -1) {
        return -1;
    }
    return 0;
}

int mt_setbgcolor(enum colors color) {
    char buf[16];
    int len = snprintf(buf, sizeof(buf), "\033[4%dm", color);
    if (write(STDOUT_FILENO, buf, len) == -1) {
        return -1;
    }
    return 0;
}

int mt_setdefaultcolor(void) {
    if (write(STDOUT_FILENO, "\033[0m", 4) == -1) {
        return -1;
    }
    return 0;
}

int mt_setcursorvisible(int value) {
    if (value) {
        if (write(STDOUT_FILENO, "\033[?25h", 6) == -1) {
            return -1;
        }
    } else {
        if (write(STDOUT_FILENO, "\033[?25l", 6) == -1) {
            return -1;
        }
    }
    return 0;
}

int mt_delline(void) {
    if (write(STDOUT_FILENO, "\033[2K", 4) == -1) {
        return -1;
    }
    return 0;
}