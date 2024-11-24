CC = gcc
CFLAGS = -Wall -g -Ifunction -IADT

SRC_DIR = function
LIB_DIR = ADT
OBJ_DIR = object
PROGRAM_DIR = aplikasi

ifeq ($(OS),Windows_NT)
    TARGET = $(PROGRAM_DIR)/PURRMART.exe
    MKDIR = if not exist $(1) mkdir $(1)
    RMDIR = if exist $(1) rmdir /s /q $(1)
else
    TARGET = $(PROGRAM_DIR)/PURRMART
    MKDIR = mkdir -p $(1)
    RMDIR = rm -rf $(1)
endif

# Main file (to separate it from other source files)
MAIN_FILE = $(LIB_DIR)/inputUserDriver.c

# Source and library files
SRC_FILES = $(LIB_DIR)/inputUser.c $(SRC_DIR)/display.c $(SRC_DIR)/delay.c $(SRC_DIR)/compare.c $(SRC_DIR)/stringToInt.c 
LIB_FILES = $(LIB_DIR)/mesinkarakter.c $(LIB_DIR)/mesinkata.c

# Object files (excluding main file)
OBJ_FILES = $(OBJ_DIR)/inputUser.o $(OBJ_DIR)/mesinkarakter.o $(OBJ_DIR)/mesinkata.o $(OBJ_DIR)/display.o $(OBJ_DIR)/delay.o $(OBJ_DIR)/compare.o $(OBJ_DIR)/stringToInt.o

# Default target
all: prepare $(TARGET)

# Prepare directories
prepare:
	$(call MKDIR,$(OBJ_DIR))
	$(call MKDIR,$(PROGRAM_DIR))

# Build the target (executable)
$(TARGET): $(OBJ_FILES) $(LIB_DIR)/inputUserDriver.o
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIB_DIR)/inputUserDriver.o -o $(TARGET)

# Compile the main file
$(LIB_DIR)/inputUserDriver.o: $(MAIN_FILE)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile .c files in SRC_DIR to .o files in OBJ_DIR
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile .c files in LIB_DIR to .o files in OBJ_DIR
$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	$(call RMDIR,$(OBJ_DIR))
	$(call RMDIR,$(PROGRAM_DIR))

# Debug rule
debug:
	@echo "Main file: $(MAIN_FILE)"
	@echo "Source files: $(SRC_FILES)"
	@echo "Library files: $(LIB_FILES)"
	@echo "Object files: $(OBJ_FILES)"
	@echo "Target: $(TARGET)"
