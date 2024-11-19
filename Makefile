CC = gcc
CFLAGS = -Wall -g -Ifunction -IADT

SRC_DIR = function
LIB_DIR = ADT
OBJ_DIR = object
PROGRAM_DIR = aplikasi

TARGET = $(PROGRAM_DIR)/PURRMART.exe
SRC_FILES = $(SRC_DIR)/inputUser.c $(SRC_DIR)/inputUserDriver.c
LIB_FILES = $(LIB_DIR)/mesinkarakter.c $(LIB_DIR)/mesinkata.c
OBJ_FILES = $(OBJ_DIR)/inputUser.o $(OBJ_DIR)/inputUserDriver.o $(OBJ_DIR)/mesinkarakter.o $(OBJ_DIR)/mesinkata.o

# Default target
all: prepare $(TARGET)

# Prepare directories
prepare:
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	@if not exist $(PROGRAM_DIR) mkdir $(PROGRAM_DIR)

# Build the target (executable)
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(TARGET)

# Generic rule to compile .c files in SRC_DIR to .o files in OBJ_DIR
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile .c files in LIB_DIR to .o files in OBJ_DIR
$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	@if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)
	@if exist $(PROGRAM_DIR) rmdir /s /q $(PROGRAM_DIR)

# Debug rule
debug:
	@echo "Library = $(LIB_DIR)"
	@echo "Object directory = $(OBJ_DIR)"
	@echo "Program directory = $(PROGRAM_DIR)"
	@echo "Target = $(TARGET)"
