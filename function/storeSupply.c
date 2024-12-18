#include "storeSupply.h"

void storeSupply(ListBarang *lb, Queue *q) {
    if (isEmpty(*q)) {
        printf("Tidak ada barang dalam antrian.\n");
        return;
    }

    // Ambil index barang dari antrian
    int idx;
    dequeue(q, &idx);
    Barang barangAntri = lb->items[idx];

    printf("Apakah kamu ingin menambahkan barang %s: ", barangAntri.name);

    // Baca input menggunakan inputUser()
    ArrayOfKata input = inputUser();

    // Validasi input
    if (input.WordCount > 0) {
        Kata inputCommand;
        for (int i = 0; i < CharMax; i++) {
            inputCommand.TabKata[i] = input.kata[0][i]; // Salin kata pertama ke tipe Kata
        }
        inputCommand.Index = 0; // Reset Index
        inputCommand.TabKata[CharMax - 1] = '\0';

        if (IsBarangNameEqual((Barang*) &(Barang){.name = "Terima"}, &inputCommand)) {
            int harga;

            // Validasi harga barang
            do {
                printf("Harga barang: ");
                scanf("%d", &harga);
                if (harga <= 0) {
                    printf("Harga harus lebih dari 0!\n");
                }
            } while (harga <= 0);

            barangAntri.price = harga;
            lb->items[lb->count++] = barangAntri; // Tambahkan barang ke toko

            printf("%s dengan harga %d telah ditambahkan ke toko.\n", barangAntri.name, barangAntri.price);

        } else if (IsBarangNameEqual((Barang*) &(Barang){.name = "Tunda"}, &inputCommand)) {
            printf("%s dikembalikan ke antrian.\n", barangAntri.name);
            enqueue(q, idx); // Kembalikan barang ke antrian

        } else if (IsBarangNameEqual((Barang*) &(Barang){.name = "Tolak"}, &inputCommand)) {
            printf("%s dihapus dari antrian.\n", barangAntri.name);
            // Barang dihapus, tidak dimasukkan kembali ke antrian

        } else {
            printf("Input tidak valid. Gunakan 'Terima', 'Tunda', atau 'Tolak'.\n");
            enqueue(q, idx); // Masukkan kembali ke antrian
        }
    } else {
        printf("Input kosong. Kembali ke menu.\n");
        enqueue(q, idx); // Masukkan kembali ke antrian
    }
}
