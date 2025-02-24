CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -ImyTerm -Isrc
LIB_DIR = myTerm
SRC_DIR = src
CONSOLE_DIR = console
BIN_DIR = bin

all: $(BIN_DIR)/console

# Создаем директорию bin, если она не существует
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/console: $(CONSOLE_DIR)/main.c $(LIB_DIR)/libmyTerm.a $(SRC_DIR)/libmySimpleComputer.a | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $< -L$(LIB_DIR) -lmyTerm -L$(SRC_DIR) -lmySimpleComputer

$(LIB_DIR)/libmyTerm.a: $(LIB_DIR)/myTerm.o
	ar rcs $@ $<

$(LIB_DIR)/myTerm.o: $(LIB_DIR)/myTerm.c $(LIB_DIR)/myTerm.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(SRC_DIR)/libmySimpleComputer.a: $(SRC_DIR)/memory.o $(SRC_DIR)/registers.o $(SRC_DIR)/commands.o $(SRC_DIR)/io.o
	ar rcs $@ $^

$(SRC_DIR)/memory.o: $(SRC_DIR)/memory.c $(SRC_DIR)/memory.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(SRC_DIR)/registers.o: $(SRC_DIR)/registers.c $(SRC_DIR)/registers.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(SRC_DIR)/commands.o: $(SRC_DIR)/commands.c $(SRC_DIR)/commands.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(SRC_DIR)/io.o: $(SRC_DIR)/io.c $(SRC_DIR)/io.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BIN_DIR) $(LIB_DIR)/*.o $(LIB_DIR)/*.a $(SRC_DIR)/*.o $(SRC_DIR)/*.a

.PHONY: all clean