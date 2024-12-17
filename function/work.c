#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "work.h"
#include "user.h"
#include "mesinkata.h"
#include "compare.h"
#include "delay.h"
#include "display.h"

void work (int idx){
    int duration, gaji;

    do {
    printf("Daftar pekerjaan:\n\n");
    printf("<> Evil Lab Assistant (pendapatan=100, durasi=14s)\n");
    printf("<> OWCA Hiring Manager (pendapatan=4200, durasi=21s)\n");
    printf("<> Cikapundunginator Caretaker (pendapatan=7000, durasi=30s)\n");
    printf("<> Mewing Specialist (pendapatan=10000, durasi=22s)\n");
    printf("<> Inator Connoisseur (pendapatan=997, durasi=15s)\n");
    printf("\nMasukkan pekerjaan yang dipilih: ");

    ArrayOfKata input = inputUser();

    if (stringCompare(input.kata[0], "Evil") && stringCompare(input.kata[1], "Lab") && stringCompare(input.kata[2], "Assistant")) {
        gaji = 100;
        userList[idx].money += 100; 
        duration = 14; 
        break; // Exit loop if valid input
    }
    else if (stringCompare(input.kata[0], "OWCA") && stringCompare(input.kata[1], "Hiring") && stringCompare(input.kata[2], "Manager")) {
        gaji = 4200;
        userList[idx].money += 4200; 
        duration = 21; 
        break; // Exit loop if valid input
    }
    else if (stringCompare(input.kata[0], "Cikapundunginator") && stringCompare(input.kata[1], "Caretaker")) {
        gaji = 7000;
        userList[idx].money += 7000; 
        duration = 30; 
        break; // Exit loop if valid input
    }
    else if (stringCompare(input.kata[0], "Mewing") && stringCompare(input.kata[1], "Specialist")) {
        gaji = 10000;
        userList[idx].money += 10000; 
        duration = 22; 
        break; // Exit loop if valid input
    }
    else if (stringCompare(input.kata[0], "Inator") && stringCompare(input.kata[1], "Connoisseur")) {
        gaji = 997;
        userList[idx].money += 997; 
        duration = 15; 
        break; // Exit loop if valid input
    } else {
        printf("\nPekerjaan tidak valid. Coba lagi.\n\n");
    }
} while (1); // Repeat until a valid input is provided

    printf("Anda sedang bekerja... harap tunggu.\n");
    delay(duration,'s');

    printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", gaji);

}