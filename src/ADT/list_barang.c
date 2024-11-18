#include "list_barang.h"
#include <stdio.h>
#include <stdlib.h>

void CreateListBarang(ListBarang *lb, int capacity) {
    lb -> items = (Barang *)malloc(capacity * sizeof(Barang));
    lb -> capacity = capacity;
    lb -> count = 0;
}

void AddBarang(ListBarang *lb, Barang b) {
    if (lb -> count < lb -> capacity) {
        lb -> items[lb -> count++] = b;
        printf("Barang berhasil ditambahkan\n");
    } else {
        printf("List Barang penuh\n");
    }

}

int FindBarang(ListBarang lb, const Word *name) {
    for (int i = 0; i < lb.count; i++) {
        if (IsBarangNameEqual(&lb.items[i], name)) {
            return i;
        }
    }
    return -1;
}

void RemoveBarang(ListBarang *lb, const Word *name) {
    int idx = FindBarang(*lb, name);
    if (idx != -1) {
        for (int i = idx; i < lb->count-1; i++) {
            lb -> items[i] = lb -> items[i+1];
        }
        lb -> count--;
    }
}

void DisplayBarangList(ListBarang lb) {
    for (int i = 0; i < lb.count; i++) {
        printf("%d. ", i + 1);
        DisplayBarang(lb.items[i]);
    }
}

void FreeListBarang(ListBarang *lb) {
    free(lb -> items);
}
