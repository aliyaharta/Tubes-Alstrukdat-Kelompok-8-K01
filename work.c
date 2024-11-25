#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void work(){
    int duration, gaji;
    char pekerjaan;

    printf("Daftar pekerjaan:\n");
    printf("1. Evil Lab Assistant (pendapatan=100, durasi=14s)\n");
    printf("2. OWCA Hiring Manager (pendapatan=4200, durasi=21s)\n");
    printf("3. Cikapundunginator Caretaker (pendapatan=7000, durasi=30s)\n");
    printf("4. Mewing Specialist (pendapatan=10000, durasi=22s)\n");
    printf("5. Inator Connoisseur (pendapatan=997, durasi=15s)\n");
    printf("\nMasukkan pekerjaan yang dipilih: ");

    scanf("%c", &pekerjaan);

    if (pekerjaan == 'Evil Lab Assistant'){
        gaji = 100;
        money += 100; 
        duration = 14; 
    }
    else if (pekerjaan == 'OWCA Hiring Manager'){
        gaji = 4200;
        money += 4200; 
        duration = 21; 
    }
    else if (pekerjaan == 'Cikapundunginator Caretaker'){
        gaji = 7000;
        money += 7000; 
        duration = 30; 
    }
    else if (pekerjaan == 'Mewing Specialist'){
        gaji = 10000;
        money += 10000; 
        duration = 22; 
    }
    else if (pekerjaan == 'Inator Connoisseur'){
        gaji = 997;
        money += 997; 
        duration = 15; 
    }
    printf("Anda sedang bekerja... harap tunggu.\n");
    delay(duration);

    money += gaji;
    printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", gaji);
}