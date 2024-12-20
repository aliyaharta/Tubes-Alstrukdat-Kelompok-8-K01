#include "challenge.h"
#include "inputUser.h"
#include "compare.h"
#include "mesinkata.h"
#include "challenge.h"
#include "user.h"

void playChallenge(int userIndex) {
    ArrayOfKata input;

    while (1) {
        printf("Daftar challenge yang tersedia :\n");
        printf("1. Tebak Angka (biaya main=200)\n");
        printf("2. W0RDL399 (biaya main=500)\n");
        printf("3. Quantum W0RDL3 (biaya main=600)\n");
        printf("Masukan challenge yang hendak dimainkan:\n");

        input = inputUser();

        if (input.WordCount > 0) {
            challenge(userIndex); 
            printf("Apakah kamu masih mau melanjutkan challenge? (y / n): \n");
            input = inputUser();

            if (input.WordCount > 0) {
                if (stringCompare(input.kata[0], "n") || stringCompare(input.kata[0], "N")) {
                    printf("Terima kasih telah bermain!\n");
                    break;
                } 
                else if (stringCompare(input.kata[0], "y") || stringCompare(input.kata[0], "Y")) {
                    continue;
                } 
                else {
                    printf("Inputan salah! Harap masukkan 'y' atau 'n'\n");
                }
            }
        }
    }
}