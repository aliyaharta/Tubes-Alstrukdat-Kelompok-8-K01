#ifndef BARANG_H
#define BARANG_H

#include "config.h"

typedef struct {
    char name[WordMax];
    int price;
} Barang;

// Deklarasi variabel global untuk Barang
extern Barang barangList[100];
extern int barangCount;

#endif // BARANG_H
