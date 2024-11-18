CC = gcc
CFLAGS = -Wall -g -Ifunction -IADT

SRC_DIR = function
LIB_DIR = ADT
OBJ_DIR = object
PROGRAM_DIR = aplikasi

TARGET = $(PROGRAM_DIR)/PURRMART.exe

SRC_FILES = $(SRC_DIR)/main.c
LIB_FILES = $(LIB_DIR)/mesinkarakter.c $(LIB_DIR)/mesinkata.c
OBJ_FILES = $(OBJ_DIR)/main.o $(OBJ_DIR)/mesinkarakter.o $(OBJ_DIR)/mesinkata.o

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	@if not exist $(PROGRAM_DIR) mkdir $(PROGRAM_DIR)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(TARGET)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c $(SRC_DIR)/boolean.h $(SRC_DIR)/main.h
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/mesinkarakter.o: $(LIB_DIR)/mesinkarakter.c $(LIB_DIR)/mesinkarakter.h $(SRC_DIR)/boolean.h
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/mesinkata.o: $(LIB_DIR)/mesinkata.c $(LIB_DIR)/mesinkata.h $(SRC_DIR)/boolean.h
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)
	@if exist $(PROGRAM_DIR) rmdir /s /q $(PROGRAM_DIR)

debug:
	@echo "Main source = $(SRC_DIR)"
	@echo "Library = $(LIB_DIR)"
	@echo "Object directory = $(OBJ_DIR)"
	@echo "Program directory = $(PROGRAM_DIR)"
	@echo "Target = $(TARGET)"
