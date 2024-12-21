#include "storeremove.h"
#include <stdio.h>

void storeremove(ListBarang *barangList) {
    if (isEmptyBarang(*barangList)) {
        printf("Tidak ada barang di toko untuk dihapus.\n");
        return;
    }
    else{
        printf("Nama barang yang akan dihapus: ");
        ArrayOfKata input = inputUser();

        if (input.WordCount > 0) {
            char itemName[WordMax];
            combineword(itemName,input);
            int idx = findItemBarang(*barangList, itemName);
            if (idx != -1) {
                for (int i = idx; i < barangList->count - 1; i++) {
                    barangList->items[i] = barangList->items[i + 1];
                }
                barangList->count--;
                printf("%s telah berhasil dihapus.\n", itemName);
            } 
            else {
                printf("Toko tidak menjual %s.\n", itemName);
            }
        } 
        else {
            printf("Input tidak valid. Kembali ke menu utama.\n");
        }
    }
}