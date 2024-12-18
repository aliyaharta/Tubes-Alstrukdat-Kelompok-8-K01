#include "storeRemove.h"

void storeRemove(ListBarang *lb) {
    printf("Nama barang yang akan dihapus: ");

    // Menggunakan inputUser untuk mendapatkan nama barang
    ArrayOfKata input = inputUser();

    if (input.WordCount == 0) {
        printf("Input tidak valid.\n");
        return;
    }

    Kata namaBarang;
    // Menyusun nama barang
    namaBarang.Index = 0;  // Reset Index
    for (int i = 0; i < input.WordCount; i++) {
        int j = 0;
        while (input.kata[i][j] != '\0' && j < CharMax) {
            namaBarang.TabKata[namaBarang.Index++] = input.kata[i][j];
            j++;
        }
        if (i != input.WordCount - 1) {
            namaBarang.TabKata[namaBarang.Index++] = ' '; // Tambahkan spasi antar kata
        }
    }
    namaBarang.TabKata[namaBarang.Index] = '\0'; // Akhiri string

    // Menghapus barang dari list
    RemoveBarang(lb, &namaBarang);
    if (FindBarang(*lb, &namaBarang) == -1) {
        printf("%s telah berhasil dihapus dari toko.\n", namaBarang.TabKata);
    } else {
        printf("Toko tidak menjual %s.\n", namaBarang.TabKata);
    }
}