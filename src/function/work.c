#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int money = 0;

void delay(int seconds) {
    int milli_seconds = seconds * 1000;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

void work() {
    int duration, gaji;
    char pekerjaan[50];

    printf("Daftar pekerjaan:\n");
    printf("1. Evil Lab Assistant (pendapatan=100, durasi=14s)\n");
    printf("2. OWCA Hiring Manager (pendapatan=4200, durasi=21s)\n");
    printf("3. Cikapundunginator Caretaker (pendapatan=7000, durasi=30s)\n");
    printf("4. Mewing Specialist (pendapatan=10000, durasi=22s)\n");
    printf("5. Inator Connoisseur (pendapatan=997, durasi=15s)\n");
    printf("\nMasukkan pekerjaan yang dipilih: ");

    fgets(pekerjaan, sizeof(pekerjaan), stdin);
    pekerjaan[strcspn(pekerjaan, "\n")] = '\0'; // Menghapus newline

    if (strcmp(pekerjaan, "Evil Lab Assistant") == 0) {
        gaji = 100;
        duration = 14;
    } else if (strcmp(pekerjaan, "OWCA Hiring Manager") == 0) {
        gaji = 4200;
        duration = 21;
    } else if (strcmp(pekerjaan, "Cikapundunginator Caretaker") == 0) {
        gaji = 7000;
        duration = 30;
    } else if (strcmp(pekerjaan, "Mewing Specialist") == 0) {
        gaji = 10000;
        duration = 22;
    } else if (strcmp(pekerjaan, "Inator Connoisseur") == 0) {
        gaji = 997;
        duration = 15;
    } else {
        printf("Pilihan tidak valid!\n");
        return;
    }

    printf("Anda sedang bekerja sebagai %s... harap tunggu.\n", pekerjaan);
    delay(duration);

    money += gaji;
    printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", gaji);
    printf("Saldo total Anda: %d rupiah.\n", money);
}

int main() {
    work();
    return 0;
}
