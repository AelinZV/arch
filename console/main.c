#include "myTerm.h"
#include "mySimpleComputer.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;

    // Проверка размера экрана
    if (mt_getscreensize(&rows, &cols)) {
        fprintf(stderr, "Ошибка получения размера экрана.\n");
        return 1;
    }

    if (rows < 24 || cols < 80) {
        fprintf(stderr, "Размер экрана слишком мал для отображения консоли.\n");
        return 1;
    }

    // Очистка экрана
    mt_clrscr();

    // Вывод текстовой информации
    mt_gotoXY(10, 5);
    mt_setfgcolor(RED);
    mt_setbgcolor(BLACK);
    printf("ILya and Ruslan\n");

    mt_gotoXY(8, 6);
    mt_setfgcolor(RED);
    mt_setbgcolor(WHITE);
    printf("IP 311\n");

    // Возврат курсора и сброс цветов
    mt_gotoXY(1, 10);
    mt_setdefaultcolor();

    // Дополнительный вывод
    mt_gotoXY(1, 12);
    mt_setfgcolor(GREEN);
    mt_setbgcolor(BLACK);
    printf("Программа успешно завершена!\n");

    return 0;
}