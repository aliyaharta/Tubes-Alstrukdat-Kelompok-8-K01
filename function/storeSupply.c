#include "storeSupply.h"

void storeSupply(Queue *antrian, ListBarang *barangList) {
    if (isEmpty(*antrian)) {
        printf("\nTidak ada barang dalam antrian.\n");
        return;
    }

    char itemName[WordMax];
    dequeue(antrian, itemName);

    printf("\nApakah kamu ingin menambahkan barang %s: ", itemName);

    // Menggunakan inputUser untuk membaca keputusan pengguna
    ArrayOfKata decision = inputUser();
    if (decision.WordCount == 1) {
        if (stringCompare(decision.kata[0], "Terima")) {
            printf("Harga barang: ");
            ArrayOfKata priceInput = inputUser();
            int price = stringToInt(priceInput.kata[0]);

            if (price > 0) {
                Barang newItem = CreateBarang(itemName, price);
                if (barangList->count < barangList->capacity) {
                    barangList->items[barangList->count++] = newItem;
                    printf("%s dengan harga %d telah ditambahkan ke toko.\n", itemName, price);
                } else {
                    printf("Gagal menambahkan barang. Kapasitas toko penuh.\n");
                }
            } else {
                printf("Harga barang tidak valid. Barang dikembalikan ke antrian.\n");
                enqueue(antrian, itemName);
            }
        } else if (stringCompare(decision.kata[0], "Tunda")) {
            enqueue(antrian, itemName);
            printf("%s dikembalikan ke antrian.\n", itemName);
        } else if (stringCompare(decision.kata[0], "Tolak")) {
            printf("%s dihapuskan dari antrian.\n", itemName);
        } else {
            printf("Input tidak valid. Kembali ke menu utama.\n");
            enqueue(antrian, itemName);
        }
    } else {
        printf("Input tidak valid. Kembali ke menu utama.\n");
        enqueue(antrian, itemName);
    }
}