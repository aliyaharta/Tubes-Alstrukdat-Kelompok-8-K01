#include <stdio.h>
#include <stdlib.h>
#include "readfile.h"

int readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 1; // Error membuka file
    }

    // Membaca jumlah barang
    fscanf(file, "%d", &barangCount);
    for (int i = 0; i < barangCount; i++) {
        fscanf(file, "%d", &barangList[i].price);
        fscanf(file, " %[^\n]s", barangList[i].name); // Membaca string hingga newline
    }

    // Membaca jumlah user
    fscanf(file, "%d", &userCount);
    for (int i = 0; i < userCount; i++) {
        fscanf(file, "%d", &userList[i].money);
        fscanf(file, "%s", userList[i].password); // Membaca password tanpa spasi
        fscanf(file, " %[^\n]s", userList[i].name); // Membaca nama hingga newline
    }

    fclose(file);
    return 0; // Berhasil membaca file
}
