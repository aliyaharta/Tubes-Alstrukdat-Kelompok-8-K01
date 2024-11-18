#include "barang.h"
#include <stdio.h>

void CreateBarang(Barang *b, const Word *name, int price) {
    for (int i = 0; i < name->Length && i < MAX_LEN - 1; i++) {
        b->name[i] = name->TabWord[i];
    }
    b->name[name->Length] = '\0';
    b->price = price;
}

void DisplayBarang(Barang b) {
    printf("Name: %s, Price: %d\n", b.name, b.price);
}

boolean IsBarangNameEqual(const Barang *b, const Word *name) {
    for (int i = 0; i < name->Length; i++) {
        if (i >= MAX_LEN || name->TabWord[i] != b->name[i]) {
            return false;
        }
    }
    return (name->Length == 0 || b->name[name->Length] == '\0');
}