#include <stdio.h>
#include <stdlib.h>
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "load.h"

int WordToInt(Word word) {
    char str[MAX_LEN];
    int i;
    for (i = 0; i < word.Length; i++) {
        str[i] = word.TabWord[i];
    }
    str[i] = '\0';
    return atoi(str);
}

void WordToString(Word word, char* str) {
    int i;
    for (i = 0; i < word.Length; i++) {
        str[i] = word.TabWord[i];
    }
    str[i] = '\0';
}

void Load(char *filename, Barang barang[], int *jumlahBarang, User user[], int *jumlahUser) {
    StartWordFile(filename, 0);

    if (EndWord) {
        printf("File tidak dapat dibuka.\n");
        return;
    }
    *jumlahBarang = WordToInt(currentWord);
    for (int i = 0; i < *jumlahBarang; i++) {
        ADVLine();
        barang[i].price = WordToInt(currentWord);
        Word namaBarang = SplitWordBlank(currentWord);
        WordToString(namaBarang, barang[i].nama);
    }

    ADVLine();

    *jumlahUser = WordToInt(currentWord);

    for (int i = 0; i < *jumlahUser; i++) {
        ADVLine();
        user[i].money = WordToInt(currentWord);
        Word temp = SplitWordBlank(currentWord);
        Word nama = SplitWordLeftBlank(temp);
        WordToString(nama, user[i].name);

        temp = SplitWordBlank(temp);
        WordToString(temp, user[i].password);
    }
}