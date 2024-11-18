#include "start.h"

void start(ListBarang *barangList, ListUser *userList) {
    if(readTxt("config.txt", barangList, userList)) {
        printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan\n");
    } else {
        printf("File konfigurasi tidak dapat dibaca\n");
    }
}