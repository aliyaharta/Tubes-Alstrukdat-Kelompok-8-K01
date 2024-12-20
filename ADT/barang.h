#ifndef BARANG_H
#define BARANG_H

#include "config.h"
#include "boolean.h"
#include "copystr.h"
#include "./../function/compare.h"

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

Barang CreateBarang(const char *name, int price);
void CreateListBarang(ListBarang *listbarang, int capacity);
boolean isEmptyBarang(ListBarang *listBarang);
int findItemBarang(ListBarang *ListBarang, char *name);

#endif // BARANG_H