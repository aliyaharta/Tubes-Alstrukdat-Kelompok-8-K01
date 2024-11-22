#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Fungsi untuk menjalankan permainan tebak angka
void tebakAngka() {
    int angkaRahasia, tebakan, percobaan = 0;
    const int batasBawah = 1, batasAtas = 100;

    // Inisialisasi angka acak
    srand(time(NULL));
    angkaRahasia = (rand() % (batasAtas - batasBawah + 1)) + batasBawah;

    printf("Selamat datang di permainan tebak angka!\n");
    printf("Saya sudah memilih angka antara %d hingga %d.\n", batasBawah, batasAtas);
    printf("Bisakah Anda menebaknya?\n");

    do {
        printf("\nMasukkan tebakan Anda: ");
        if (scanf("%d", &tebakan) != 1) { // Validasi input
            printf("Harap masukkan angka yang valid.\n");
            while (getchar() != '\n'); // Bersihkan input buffer
            continue;
        }

        percobaan++;
        if (tebakan < angkaRahasia) {
            printf("Terlalu kecil. Coba lagi!\n");
        } else if (tebakan > angkaRahasia) {
            printf("Terlalu besar. Coba lagi!\n");
        } else {
            printf("Selamat! Anda berhasil menebak angka dalam %d percobaan.\n", percobaan);
        }
    } while (tebakan != angkaRahasia);
}

int main() {
    tebakAngka();
    return 0;
}
