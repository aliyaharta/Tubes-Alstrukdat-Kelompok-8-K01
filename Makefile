CC = gcc
CFLAGS = -Wall -g -Ifunction -IADT

SRC_DIR = function
LIB_DIR = ADT
OBJ_DIR = object
PROGRAM_DIR = aplikasi

TARGET = $(PROGRAM_DIR)/PURRMART.exe

# Main file (to separate it from other source files)
MAIN_FILE = $(SRC_DIR)/main.c

# Source and library files
SRC_FILES = $(SRC_DIR)/inputUser.c $(SRC_DIR)/display.c $(SRC_DIR)/delay.c
LIB_FILES = $(LIB_DIR)/mesinkarakter.c $(LIB_DIR)/mesinkata.c

# Object files (excluding main file)
OBJ_FILES = $(OBJ_DIR)/inputUser.o $(OBJ_DIR)/mesinkarakter.o $(OBJ_DIR)/mesinkata.o $(SRC_DIR)/display.o $(SRC_DIR)/delay.o

# Default target
all: prepare $(TARGET)

# Prepare directories
prepare:
ifeq ($(OS),Windows_NT)
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	@if not exist $(PROGRAM_DIR) mkdir $(PROGRAM_DIR)
else
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(PROGRAM_DIR)
endif

# Build the target (executable)
$(TARGET): $(OBJ_FILES) $(OBJ_DIR)/main.o
	$(CC) $(CFLAGS) $(OBJ_FILES) $(OBJ_DIR)/main.o -o $(TARGET)

# Compile the main file
$(OBJ_DIR)/main.o: $(MAIN_FILE)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile .c files in SRC_DIR to .o files in OBJ_DIR
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile .c files in LIB_DIR to .o files in OBJ_DIR
$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
ifeq ($(OS),Windows_NT)
	@if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)
	@if exist $(PROGRAM_DIR) rmdir /s /q $(PROGRAM_DIR)
else
	@rm -rf $(OBJ_DIR)
	@rm -rf $(PROGRAM_DIR)
endif

# Debug rule
debug:
	@echo "Main file: $(MAIN_FILE)"
	@echo "Source files: $(SRC_FILES)"
	@echo "Library files: $(LIB_FILES)"
	@echo "Object files: $(OBJ_FILES)"
	@echo "Target: $(TARGET)"
