#include <stdio.h>
#include "user.h"
#include "barang.h"
#include "writefile.h"

void writeFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    // Menulis jumlah barang
    fprintf(file, "%d\n", barangCount);
    for (int i = 0; i < barangCount; i++) {
        fprintf(file, "%d %s\n", barangList[i].price, barangList[i].name);
    }

    // Menulis jumlah user
    fprintf(file, "%d\n", userCount);
    for (int i = 0; i < userCount; i++) {
        fprintf(file, "%d %s %s\n", userList[i].money, userList[i].password, userList[i].name);
    }

    fclose(file);
    printf("Data telah berhasil disimpan ke %s\n", filename);
}
