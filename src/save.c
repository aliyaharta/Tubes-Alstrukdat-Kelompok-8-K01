#include <stdio.h>
#include "list_barang.h"
#include "list_user.h"

void SaveProgram(ListBarang lb, ListUser lu, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Gagal membuka file %s untuk menyimpan data.\n", filename);
        return;
    }

    // simpan jumlah barang 
    fprintf(file, "%d\n", lb.count);

    // simpan barang
    for (int i = 0; i < lb.count; i++) {
        fprintf(file, "%d %s\n", lb.items[i].price, lb.items[i].name);
    }

    // simpan jumlah user
    fprintf(file, "%d\n", lu.count);

    // simpan user
    for (int i = 0; i < lu.count; i++) {
        fprintf(file, "%d %s %s\n", lu.users[i].money, lu.users[i].name, lu.users[i].password);
    }

    fclose(file);
    printf("Data berhasil disimpan ke file: %s\n", filename);
}