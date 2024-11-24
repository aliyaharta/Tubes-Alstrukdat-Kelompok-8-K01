#include <stdio.h>
#include "mesinkata.h"
#include "config.h"

int main(void) {
    char filename[100];

    printf("Masukkan nama file:");
    scanf("%s", filename);

    STARTKATA(filename);
    if(IsEndKata()) {
        printf("File kosong tidak ada kata yang dibaca.\n");
        return 0;
    }

    printf("Kata-kata dalam file:\n");
    while (!IsEndKata()) {
        Kata current = GetCKata();
        printf("Panjang kata: %d\n", getLength(current));
        ADVKATA();
    }

    printf("Selesai membaca file.\n");
    return 0;
}