#include <stdio.h>
#include <string.h>
#include "quit.h"
#include "save.h" // Untuk memanggil fungsi SAVE

void QUIT(ListBarang *barangList, ListUser *userList) {
    char response;
    printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");
    scanf(" %c", &response);

    if (response == 'Y' || response == 'y') {
        char filename[100];
        printf("Masukkan nama file untuk menyimpan sesi: ");
        scanf("%s", filename);

        if (SAVE(filename, barangList, userList)) {
            printf("Data berhasil disimpan ke %s. Dadah ^_^/\n", filename);
        } else {
            printf("Gagal menyimpan data. Dadah ^_^/\n");
        }
    } else if (response == 'N' || response == 'n') {
        printf("Kamu keluar dari PURRMART. Dadah ^_^/\n");
    } else {
        printf("Input tidak valid. Silakan ulangi proses quit.\n");
    }
}