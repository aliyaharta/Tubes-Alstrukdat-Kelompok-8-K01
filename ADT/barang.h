#ifndef BARANG_H
#define BARANG_H

#include "config.h"
#include "boolean.h"
#include "mesinkata.h"
#include "mesinkarakter.h"

typedef struct {
    char name[WordMax];
    int price;
} Barang;

// Deklarasi variabel global untuk Barang
extern Barang barangList[100];
extern int barangCount;

// Fungsi untuk barang baru
void CreateBarang(Barang *b, const Kata *name, int price);

// Tampilin informasi dari barang
void DisplayBarang(Barang b);

boolean IsBarangNameEqual(const Barang *b, const Kata *name);

#endif // BARANG_H
