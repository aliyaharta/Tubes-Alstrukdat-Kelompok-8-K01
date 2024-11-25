#include "playChallenge.h"
#include "challenge.h"
#include "inputUser.h"

void playChallenge (){
    printf("Daftar challenge yang tersedia :\n");
    printf("1. Tebak Angka (biaya main=200)\n"); 
    printf("2. W0RDL399 (biaya main=500)\n");
    printf("3. Quantum W0RDL3 (biaya main = 600)\n");
    printf("Masukan challenge yang hendak dimainkan:\n");

    challenge();


    printf("Apakah kamu masih mau melanjutkan challenge? (y / n): \n");
    ArrayOfKata y = inputUser();
    char tanya[6] = y.kata[0];

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