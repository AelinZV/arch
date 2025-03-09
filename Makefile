CC = gcc
CFLAGS = -Wall -Wextra -std=c11
INCLUDES = -ImyTerm -Isrc -ImyBigChars
LIBS = -LmyTerm -lmyTerm -LmyBigChars -lmyBigChars -Lsrc -lmySimpleComputer -lm

# Объектные файлы
MYTERM_OBJ = myTerm/myTerm.o
MYBIGCHARS_OBJ = myBigChars/myBigChars.o
SRC_OBJ = src/memory.o src/registers.o src/commands.o src/io.o

# Цели
all: myTerm/libmyTerm.a myBigChars/libmyBigChars.a src/libmySimpleComputer.a bin/console bin/font

# Сборка библиотеки myTerm
myTerm/libmyTerm.a: $(MYTERM_OBJ)
	ar rcs $@ $^

# Сборка библиотеки myBigChars
myBigChars/libmyBigChars.a: $(MYBIGCHARS_OBJ)
	ar rcs $@ $^

# Сборка библиотеки mySimpleComputer
src/libmySimpleComputer.a: $(SRC_OBJ)
	ar rcs $@ $^

# Сборка консольного приложения
bin/console: console/main.c myTerm/libmyTerm.a myBigChars/libmyBigChars.a src/libmySimpleComputer.a $(SRC_OBJ) $(MYTERM_OBJ) $(MYBIGCHARS_OBJ)
	mkdir -p bin
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ console/main.c $(SRC_OBJ) $(MYTERM_OBJ) $(MYBIGCHARS_OBJ) myTerm/libmyTerm.a myBigChars/libmyBigChars.a src/libmySimpleComputer.a

# Сборка программы font
bin/font: console/font.c myTerm/libmyTerm.a myBigChars/libmyBigChars.a src/libmySimpleComputer.a $(SRC_OBJ) $(MYTERM_OBJ) $(MYBIGCHARS_OBJ)
	mkdir -p bin
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ console/font.c $(SRC_OBJ) $(MYTERM_OBJ) $(MYBIGCHARS_OBJ) myTerm/libmyTerm.a myBigChars/libmyBigChars.a src/libmySimpleComputer.a

# Компиляция объектных файлов
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

# Очистка
clean:
	rm -f $(MYTERM_OBJ) $(MYBIGCHARS_OBJ) $(SRC_OBJ) myTerm/libmyTerm.a myBigChars/libmyBigChars.a src/libmySimpleComputer.a bin/console bin/font
	rm -rf bin
