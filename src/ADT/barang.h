#ifndef BARANG_H
#define BARANG_H

#include "mesinkata.h"

#define MAX_LEN 50

typedef struct {
    Word name[MAX_LEN];
    int price;
} Barang;

// Fungsi untuk barang baru
void CreateBarang(Barang *b, const Word *name, int price);

// Tampilin informasi dari barang
void DisplayBarang(Barang b);

boolean IsBarangNameWqual(const Barang *b, const Word *name);

#endif
