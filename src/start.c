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
        jumlahBarang = jumlahBarang * 10 + (CurrentWord.TabWord[i] - '0');
    }
    ADVWORD();

    // Baca Barang
    for (int i = 0; i < jumlahBarang; i++) {
        Word harga, namaBarang;

        // membaca harga barangnya
        harga = CurrentWord;
        ADVWORD();

        // membaca nama barangnya
        namaBarang = CurrentWord;
        ADVWORD();

        // konversi harga
        int hargaBarang = 0;
        for (int j = 0; j < harga.Length; j++) {
            hargaBarang = hargaBarang * 10 + (harga.TabWord[j] - '0');
        }

        // tambah barang ke list 
        Barang b;
        CreateBarang(&b, &namaBarang, hargaBarang);
        AddBarang(lb, b);
    }

    // baca jumlah user
    int jumlahUser = 0;
    for (int i = 0; i < CurrentWord.Length; i++) {
        jumlahUser = jumlahUser * 10 + (CurrentWord.TabWord[i] - '0');
    }
    ADVWORD();

    // baca data user
    for (int i = 0; i < jumlahUser; i++) {
        Word username, uang, password;

        uang = CurrentWord;
        ADVWORD();

        username = CurrentWord;
        ADVWORD();

        password = CurrentWord;
        ADVWORD();

        // konversi uang
        int uangUser = 0;
        for (int j = 0; j < uang.Length; j++) {
            uangUser = uangUser * 10 + (uang.TabWord[j] - '0');
        }

        User u;
        CretaeUser(&u, &username, &password, uangUser);
        AddUser(lu, u);
    }
    printf("Konfigurasi berhasil dimuat.\n");
}