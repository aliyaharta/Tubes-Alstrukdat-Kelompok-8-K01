#include <stdio.h>
#include "src/ADT/list_barang.h"
#include "storeList.h"  

int main() {
    ListBarang toko;
    CreateListBarang(&toko, 10);  // Kapasitas maksimal 10 barang

    // Membuat barang
    Barang b1, b2, b3, b4, b5, b6;
    CreateBarang(&b1, "Platypus Laser", 500);
    CreateBarang(&b2, "Shrink Ray", 300);
    CreateBarang(&b3, "Net Shooter", 400);
    CreateBarang(&b4, "Camouflage Cloak", 350);
    CreateBarang(&b5, "Sleep Dart Gun", 250);
    CreateBarang(&b6, "Bubble Blaster", 450);

    // Menambahkan barang ke ListBarang
    AddBarang(&toko, b1);
    AddBarang(&toko, b2);
    AddBarang(&toko, b3);
    AddBarang(&toko, b4);
    AddBarang(&toko, b5);
    AddBarang(&toko, b6);

    // Panggil fungsi STORE LIST
    printf(">> STORE LIST\n");
    storeList(toko);

    // Bebaskan memori list barang
    FreeListBarang(&toko);

    return 0;
}
