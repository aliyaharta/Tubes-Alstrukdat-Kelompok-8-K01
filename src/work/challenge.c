#include <stdio.h>

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

int main (){
    printf("Daftar challenge yang tersedia :\n");
    printf("1. Tebak Angka (biaya main=200)\n"); 
    printf("2. W0RDL399 (biaya main=500)\n");
    printf("3. Quantum W0RDL3 (biaya main = 600)\n");
    printf("Masukan challenge yang hendak dimainkan:\n");

    challenge();

    char tanya;
    getchar();
    printf("Apakah kamu masih mau melanjutkan challenge? (y / n): \n");
    scanf("%c", &tanya);

    while (tanya != 'n'){
        if (tanya == 'y'){
            printf("Daftar challenge yang tersedia :\n");
            printf("1. Tebak Angka (biaya main=200)\n"); 
            printf("2. W0RDL399 (biaya main=500)\n");
            printf("3. Quantum W0RDL3 (biaya main = 600)\n");
            printf("Masukan challenge yang hendak dimainkan:\n");

            challenge();
            getchar();
        }
        else if (tanya != 'y'){
            printf("Inputan salah! Input antara 'y' atau 'n'\n");
            getchar();
            scanf("%c", &tanya);
        }
        printf("Apakah kamu masih mau melanjutkan challenge? (y / n): \n");
        scanf("%c", &tanya);
    }
}
