#include "myBigChars.h"
#include "myTerm.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int big[2] = {0};
    // Генерация шрифта
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            bc_setbigcharpos(big, i, j, 1);
        }
    }

    // Запись шрифта в файл
    FILE *file = fopen("font.bin", "wb");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }
    fwrite(big, sizeof(int), 2, file);
    fclose(file);

    printf("Font generated and saved to font.bin\n");
    return 0;
}