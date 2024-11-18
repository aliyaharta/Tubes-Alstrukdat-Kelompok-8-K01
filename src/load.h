#ifndef LOAD_H
#define LOAD_H

#include "ADT/mesinkarakter.h"
#include "ADT/mesinkata.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100
#define MAX_BARANG 100
#define MAX_USER 100

// Struktur data Barang
typedef struct {
    char nama[MAX_LEN];
    int price;
} Barang;

// Struktur Data User
typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    int money;
} User;

// konversi word ke integer
int WordToInt(Word word);

// copy word ke string
void WordToString(Word word, char* str);

// memuat data dari file
void Load(char *filename, Barang barang [], int *jumlahBarang, User user[], int *jumlahUser);

#endif