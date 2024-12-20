#ifndef LIST_BARANG_H
#define LIST_BARANG_H

#include "barang.h"

typedef struct {
    Barang *items;
    int capacity;
    int count;
} ListBarang;

void CreateListBarang(ListBarang *lb, int capacity);
void AddBarang(ListBarang *lb, Barang b);
int FindBarang(ListBarang lb, const Word *name);
void RemoveBarang(ListBarang *lb, const Word *name);
void DisplayBarangList(ListBarang lb);
void FreeListBarang(ListBarang *lb);

#endif