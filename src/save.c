#include <stdio.h>
#include "save.h"

int SAVE(const char *filename, ListBarang *barangList, ListUser *userList) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Gagal menyimpan file: %s\n", filename);
        return 0; // Gagal menyimpan
    }

    // Simpan jumlah barang
    fprintf(file, "%d\n", barangList->size);
    for (int i = 0; i < barangList->size; i++) {
        fprintf(file, "%d %s\n", barangList->items[i].price, barangList->items[i].name);
    }

    // Simpan jumlah pengguna
    fprintf(file, "%d\n", userList->size);
    for (int i = 0; i < userList->size; i++) {
        fprintf(file, "%d %s %s\n", userList->items[i].money, userList->items[i].name, userList->items[i].password);
    }

    fclose(file);
    printf("Save file berhasil disimpan ke: %s\n", filename);
    return 1; // Berhasil menyimpan
}
