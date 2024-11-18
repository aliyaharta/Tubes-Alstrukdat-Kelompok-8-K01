#include <stdio.h>
#include "src/ADT/list_barang.h"
#include "storeList.h"  

int main() {
    ListBarang l;
    CreateListBarang(&l, 10);

    Barang a, b, c, d, e, f;
    Word w1 = {"Platypus Laser", 14};
    Word w2 = {"Shrink Ray", 10};
    Word w3 = {"Net Shooter", 11};
    Word w4 = {"Platypus Laser", 14}; // Duplikat
    Word w5 = {"Camouflage Cloak", 17};
    Word w6 = {"Bubble Blaster", 14};

    CreateBarang(&a, &w1, 1000);
    CreateBarang(&b, &w2, 2000);
    CreateBarang(&c, &w3, 3000);
    CreateBarang(&d, &w4, 1000); // Barang duplikat
    CreateBarang(&e, &w5, 5000);
    CreateBarang(&f, &w6, 6000);

    AddBarang(&l, a);
    AddBarang(&l, b);
    AddBarang(&l, c);
    AddBarang(&l, d);
    AddBarang(&l, e);
    AddBarang(&l, f);

    storeList(l); // Panggil fungsi untuk menampilkan daftar barang

    FreeListBarang(&l);
    return 0;
}
