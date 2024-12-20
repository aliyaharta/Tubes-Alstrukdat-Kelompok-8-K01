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
MAIN_FILE = $(SRC_DIR)/main.c #/\#

# Source and library files
SRC_FILES = $(SRC_DIR)/display.c $(SRC_DIR)/delay.c $(SRC_DIR)/compare.c $(SRC_DIR)/stringToInt.c $(SRC_DIR)/readfile.c $(SRC_DIR)/writefile.c $(SRC_DIR)/work.c $(SRC_DIR)/storelist.c $(SRC_DIR)/storerequest.c  $(SRC_DIR)/wordl3.c  $(SRC_DIR)/wordCheck.c  $(SRC_DIR)/toUpperCase.c  $(SRC_DIR)/tebakangka.c  $(SRC_DIR)/rng.c  $(SRC_DIR)/quantumWordle.c  $(SRC_DIR)/playChallenge.c  $(SRC_DIR)/charCheck.c  $(SRC_DIR)/challenge.c $(SRC_DIR)/stringLength.c $(SRC_DIR)/wishlistadd.c $(SRC_DIR)/wishlistclear.c $(SRC_DIR)/wishlistremove.c $(SRC_DIR)/wishlistremovei.c $(SRC_DIR)/wishlistswap.c

LIB_FILES = $(LIB_DIR)/mesinkarakter.c $(LIB_DIR)/mesinkata.c $(LIB_DIR)/inputUser.c $(LIB_DIR)/user.c $(LIB_DIR)/barang.c $(LIB_DIR)/copystr.c $(LIB_DIR)/queue.c $(LIB_DIR)/combineword.c $(LIB_DIR)/linkedlist.c

# Object files (excluding main file)
OBJ_FILES = $(OBJ_DIR)/inputUser.o $(OBJ_DIR)/mesinkarakter.o $(OBJ_DIR)/mesinkata.o $(OBJ_DIR)/display.o $(OBJ_DIR)/delay.o $(OBJ_DIR)/compare.o $(OBJ_DIR)/stringToInt.o $(OBJ_DIR)/user.o $(OBJ_DIR)/barang.o $(OBJ_DIR)/readfile.o $(OBJ_DIR)/writefile.o $(OBJ_DIR)/copystr.o $(OBJ_DIR)/work.o $(OBJ_DIR)/storelist.o $(OBJ_DIR)/storerequest.o $(OBJ_DIR)/queue.o $(OBJ_DIR)/combineword.o $(OBJ_DIR)/wordl3.o $(OBJ_DIR)/wordCheck.o $(OBJ_DIR)/toUpperCase.o $(OBJ_DIR)/tebakangka.o $(OBJ_DIR)/rng.o $(OBJ_DIR)/quantumWordle.o $(OBJ_DIR)/playChallenge.o $(OBJ_DIR)/charCheck.o $(OBJ_DIR)/challenge.o $(OBJ_DIR)/stringLength.o $(OBJ_DIR)/wishlistadd.o $(OBJ_DIR)/wishlistclear.o $(OBJ_DIR)/wishlistremove.o $(OBJ_DIR)/wishlistremovei.o $(OBJ_DIR)/wishlistshow.o $(OBJ_DIR)/wishlistswap.o 

# Default target
all: prepare $(TARGET)

# Prepare directories
prepare:
	$(call MKDIR,$(OBJ_DIR))
	$(call MKDIR,$(PROGRAM_DIR))

# Build the target (executable)
$(TARGET): $(OBJ_FILES) $(OBJ_DIR)/main.o #/\#
	$(CC) $(CFLAGS) $(OBJ_FILES) $(OBJ_DIR)/main.o -o $(TARGET) 

# Compile the main file
$(OBJ_DIR)/main.o: $(MAIN_FILE) #/\#
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
