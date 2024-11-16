#include "mesinkata.h"
#include "list_barang.h"
#include "list_user.h"

// Mulai program
void StartProgram(ListBarang *lb, ListUser *lu, char *filename) {
    STARTWORD(filename);
    if (EndWord) {
        printf("File konfigurasi tidak ditemukan atau kosong.\n");
        return;
    }

    // Baca jumlah barang
    int jumlahBarang = 0;
    for (int i = 0; i < CurrentWord.Length; i++) {
        jumlahBarang;
    }


}