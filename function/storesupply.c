#include "storesupply.h"

// pengecekan jika input tidak valid masih loss
void storesupply(Queue *antrian, ListBarang *barangList) {
    if (isEmpty(*antrian)) {
        printf("Tidak ada barang dalam antrian.\n");
        return;
    }
    else {
        char item[WordMax];
        copyString(item, antrian->items[antrian->head]);

        printf("Apakah kamu ingin menambahkan barang %s : \n", item);
        ArrayOfKata decision = inputUser();

        if (decision.WordCount == 1) {
            if (stringCompare(decision.kata[0], "Terima")) {
                printf("Harga barang: ");
                ArrayOfKata priceInput = inputUser();
                char* angka = priceInput.kata[0];

                boolean isNumber = true;
                for (int i = 0; angka[i] != '\0'; i++) {
                    if (angka[i] < '0' || angka[i] > '9') {
                        isNumber = false;
                        break;
                    }
                }
                if(isNumber){
                    int price = stringToInt(angka);
                    if (price > 0) {
                        char itemName[WordMax];
                        dequeue(antrian,itemName);
                        Barang newItem = CreateBarang(itemName, price);
                        if (barangList->count < barangList->capacity) {
                            barangList->items[barangList->count++] = newItem;
                            printf("%s dengan harga %d telah ditambahkan ke toko.\n", itemName, price);
                        }
                        else {
                            printf("Gagal menambahkan barang. Kapasitas toko penuh.\n");
                        }
                    }
                    else{
                    printf("Harga barang tidak valid. Antrian tetap. Kembali ke menu utama.\n");
                    } 
                }
                else{
                    printf("Harga barang tidak valid. Antrian tetap. Kembali ke menu utama. \n");
                }
            } 
            else if (stringCompare(decision.kata[0], "Tunda")) {
                char itemName[WordMax];
                dequeue(antrian,itemName);
                enqueue(antrian,itemName);
                printf("%s dikembalikan ke antrian.\n", itemName);
            } 
            else if (stringCompare(decision.kata[0], "Tolak")) {
                char itemName[WordMax];
                dequeue(antrian,itemName);
                printf("%s dihapuskan dari antrian.\n", itemName);
            } 
            else {
                printf("Input tidak valid. Antrian tetap. Kembali ke menu utama.\n");
            }
        } 
        else {
            printf("Input tidak valid. Antrian tetap. Kembali ke menu utama.\n");
        }
    }
}