#include <stdio.h>
#include "challenge.h"

const char *word_list[] = {"TRULY", "LUCKY", "BUILD", "PLUCK", "STORM"};
const int word_count = 5;

int money = 1000;

void challenge (){
        int angka;
        scanf("%d", &angka);

        if (angka == 1){
            if (money < 200){
                printf("Uang yang dimiliki kurang! Silakan kerja terlebih dahulu.");
            }
            else{
                money -= 200;
                printf("Masukkan tebakanmu!\n");
                tebakangka();
            }
        }
        else if (angka == 2){
            if (money < 500){
                printf("Uang yang dimiliki kurang! Silakan cari challenge lain atau kerja terlebih dahulu.");
            }
            else{
                money-=500;
                wordl3();
            }
        }
        else if (angka == 3){
            if (money < 600){
                printf("Uang yang dimiliki kurang! Silakan cari challenge lain atau kerja terlebih dahulu.");
            }
            else {
                money-=600;
                quantumWordle();
            }
        }
    }
