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
    fprintf(file, "%d\n", barangList.count);
    for (int i = 0; i < barangList.count; i++) {
        fprintf(file, "%d %s\n", barangList.items[i].price, barangList.items[i].name);
    }

    // Menulis jumlah user
    fprintf(file, "%d\n", userCount);
    for (int i = 0; i < userCount; i++) {
        fprintf(file, "%d %s %s\n", userList[i].money, userList[i].password, userList[i].name);
    }

    fclose(file);
    printf("Data telah berhasil disimpan ke %s\n", filename);
}
