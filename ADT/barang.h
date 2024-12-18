#ifndef BARANG_H
#define BARANG_H

#include "config.h"
#include "boolean.h"

typedef struct {
    char name[WordMax];
    int price;
} Barang;

typedef struct {
    Barang *items;
    int capacity;
    int count;
} ListBarang;

// Deklarasi variabel global untuk Barang
extern ListBarang barangList;

void CreateListBarang(ListBarang *listbarang, int capacity);
boolean isEmptyBarang(ListBarang *listBarang);

#endif // BARANG_H