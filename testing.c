#include <stdio.h>
#include "src/ADT/list_barang.h"
#include "src/ADT/queue.h"
#include "src/ADT/mesinkarakter.h"
#include "storeRequest.h"
#include "storeList.h"

int main() {
    ListBarang lb;
    Queue q;

    CreateListBarang(&lb, 10);
    CreateQueue(&q);

    // Array data barang
    Word dataBarang[] = {
        {"Platypus Laser", 14},
        {"Shrink Ray", 10},
        {"Net Shooter", 11},
        {"Camouflage Cloak", 12},
        {"Sleep Dart Gun", 14},
        {"Bubble Blaster", 15},
    //    {"Shrink Ray", 10} // duplikat
    };
    int hargaBarang[] = {100, 200, 150, 300, 400, 200}; // Harga untuk masing-masing barang
    int jumlahBarang = sizeof(hargaBarang) / sizeof(hargaBarang[0]);
    
    printf(">> STORE LIST\n");
    storeList(lb);
    // Menambahkan barang awal ke toko (hanya barang pertama hingga ketiga)
    for (int i = 0; i < 6; i++) {
        Barang b;
        CreateBarang(&b, &dataBarang[i], hargaBarang[i]);
        AddBarang(&lb, b);
    }

    // Testing storeList
    printf(">> STORE LIST\n");
    storeList(lb);

    // Testing storeRequest untuk barang berikutnya (keempat hingga terakhir)
    printf("\n>> STORE REQUEST\n");
    for (int i = 3; i < jumlahBarang; i++) {
        storeRequest(lb, &q, &dataBarang[i]);
    }

    // Display antrean
    printf("\nAntrean barang:\n");
    displayQueue(q);

    // Display barang di toko

    // Free memory untuk list barang
    FreeListBarang(&lb);


    return 0;
}
