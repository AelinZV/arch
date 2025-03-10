#!/bin/bash

# Очистка экрана
echo -e "\033[2J"

# Вход в режим псевдографики
echo -e "\033(0"

# Вывод рамки
echo -e "\033[5;10Hlqqqqqqqqqqqqqqqqqqk"
for i in {1..8}; do
    echo -e "\033[$(($i + 5));10Hx                  x"
done
echo -e "\033[14;10Hmqqqqqqqqqqqqqqqqqqj"

# Выход из режима псевдографики
echo -e "\033(B"

# ASCII-арт головы волка (упрощенный)
echo -e "\033[6;12H\033[37m /\\_/\\  "
echo -e "\033[7;12H( o.o ) "
echo -e "\033[8;12H > ^ <  \033[0m"

# Вывод названия игры в цвете
echo -e "\033[10;13H\033[31;40mTHE WITCHER\033[0m"
echo -e "\033[11;14H\033[37;40mWILD HUNT\033[0m"

# Перемещение курсора вниз
echo -e "\033[20;1H\033[0m"
