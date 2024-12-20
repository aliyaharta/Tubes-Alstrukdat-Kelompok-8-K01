#include "storeRemove.h"

void storeRemove(ListBarang *barangList) {
    if (isEmptyBarang(barangList)) {
        printf("\nTidak ada barang di toko untuk dihapus.\n");
        return;
    }

    printf("\nNama barang yang akan dihapus: ");
    ArrayOfKata input = inputUser();

    if (input.WordCount == 1) {
        char *itemName = input.kata[0];
        int idx = findItemBarang(barangList, itemName);
        if (idx != -1) {
            for (int i = idx; i < barangList->count - 1; i++) {
                barangList->items[i] = barangList->items[i + 1];
            }
            barangList->count--;
            printf("%s telah berhasil dihapus.\n", itemName);
        } else {
            printf("Toko tidak menjual %s.\n", itemName);
        }
    } else {
        printf("Input tidak valid. Kembali ke menu utama.\n");
    }
}