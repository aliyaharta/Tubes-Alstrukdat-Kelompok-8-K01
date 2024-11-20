CC = gcc

OUTPUT_FOLDER = bin

DEBUG_CFLAG = -fshort-wchar -g

main:
	@$(CC) $(DEBUG_CFLAG) -c src/ADT/barang.c -o ${OUTPUT_FOLDER}/barang.o
	@$(CC) $(DEBUG_CFLAG) -c src/ADT/list_barang.c -o ${OUTPUT_FOLDER}/list_barang.o
	@$(CC) $(DEBUG_CFLAG) -c src/ADT/list_user.c -o ${OUTPUT_FOLDER}/list_user.o
	@$(CC) $(DEBUG_CFLAG) -c src/ADT/mesinkarakter.c -o ${OUTPUT_FOLDER}/mesinkarakter.o
	@$(CC) $(DEBUG_CFLAG) -c src/ADT/mesinkata.c -o ${OUTPUT_FOLDER}/mesinkata.o
	@$(CC) $(DEBUG_CFLAG) -c src/ADT/queue.c -o ${OUTPUT_FOLDER}/queue.o
	@$(CC) $(DEBUG_CFLAG) -c src/ADT/user.c -o ${OUTPUT_FOLDER}/user.o
	@$(CC) $(DEBUG_CFLAG) -c storeList.c -o ${OUTPUT_FOLDER}/storeList.o
	@$(CC) $(DEBUG_CFLAG) -c storeRequest.c -o ${OUTPUT_FOLDER}/storeRequest.o
	@$(CC) $(DEBUG_CFLAG) -c testing.c -o ${OUTPUT_FOLDER}/testing.o
	@$(CC) -o $(OUTPUT_FOLDER)/testing ${OUTPUT_FOLDER}/*.o
