#include "commands.h"
#include <stddef.h>

int sc_commandEncode(int sign, int command, int operand, int* value) {
    if (sign < 0 || sign > 1 || command < 0 || command > 31 || operand < 0 || operand >= 128) {
        return -1;
    }
    *value = (sign << 15) | (command << 7) | (operand & 0x7F);
    return 0;
}

int sc_commandDecode(int value, int* sign, int* command, int* operand) {
    if (sign == NULL || command == NULL || operand == NULL) {
        return -1;
    }
    *sign = (value >> 15) & 1;
    *command = (value >> 7) & 0x1F;
    *operand = value & 0x7F;
    return 0;
}

int sc_commandValidate(int command) {
    return (command >= 0 && command <= 31) ? 0 : -1;
}