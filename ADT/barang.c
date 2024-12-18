#include "barang.h"
#include <stdio.h>

// typedef struct {
//     char name[WordMax];
//     int price;
// } Barang;

// Definisi variabel global untuk Barang
Barang barangList[100];
int barangCount = 0;

void CreateBarang(Barang *b, const Kata *name, int price) {
    for (int i = 0; i < name->Length && i < WordMax - 1; i++) {
        b->name[i] = name->TabKata[i];
    }
    b->name[name->Length] = '\0';
    b->price = price;
}

void DisplayBarang(Barang b) {
    printf("Name: %s, Price: %d\n", b.name, b.price);
}

boolean IsBarangNameEqual(const Barang *b, const Kata *name) {
    for (int i = 0; i < name->Length; i++) {
        if (i >= WordMax || name->TabKata[i] != b->name[i]) {
            return false;
        }
    }
    return (name->Length == 0 || b->name[name->Length] == '\0');
}