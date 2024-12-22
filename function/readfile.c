#include <stdio.h>
#include <stdlib.h>
#include "readfile.h"
#include "barang.h"

int readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 1; // Error membuka file
    }

    // Membaca jumlah barang
    CreateListBarang(&barangList,100);
    fscanf(file, "%d", &barangList.count);
    for (int i = 0; i < barangList.count; i++) {
        fscanf(file, "%d", &barangList.items[i].price);
        fscanf(file, " %[^\n]s", barangList.items[i].name); // Membaca string hingga newline
    }

    // Membaca jumlah user
    fscanf(file, "%d", &userCount);
    for (int i = 0; i < userCount; i++) {
        fscanf(file, "%d", &userList[i].money);
        fscanf(file, "%s", userList[i].name); // Membaca password tanpa spasi
        fscanf(file, " %[^\n]s", userList[i].password); // Membaca nama hingga newline
    }

    fclose(file);
    return 0; // Berhasil membaca file
}
