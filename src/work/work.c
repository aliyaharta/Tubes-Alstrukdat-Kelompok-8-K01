#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void work (User *user){
    char pekerjaan[100];
    int duration, gaji;

    printf("Daftar pekerjaan:\n");
    printf("1. Evil Lab Assistant (pendapatan=100, durasi=14s)\n");
    printf("2. OWCA Hiring Manager (pendapatan=4200, durasi=21s)\n");
    printf("3. Cikapundunginator Caretaker (pendapatan=7000, durasi=30s)\n");
    printf("4. Mewing Specialist (pendapatan=10000, durasi=22s)\n");
    printf("5. Inator Connoisseur (pendapatan=997, durasi=15s)\n");
    printf("\nMasukkan pekerjaan yang dipilih (1-5): ");

    bacakata(pekerjaan, 100);

    if (pekerjaan == 1){
        gaji =+ 100; 
        duration = 14; 
    }
    else if (pekerjaan = 2){
        gaji =+ 4200; 
        duration = 21; 
    }
    else if (pekerjaan = 3){
        gaji =+ 7000; 
        duration = 30; 
    }
    else if (pekerjaan = 4){
        gaji =+ 10000; 
        duration = 22; 
    }
    else if (pekerjaan = 5){
        money =+ 997; 
        duration = 15; 
    }
    printf("Anda sedang bekerja... harap tunggu.\n");
    delay(duration);

    (*user).money += gaji;
    printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", gaji);
}