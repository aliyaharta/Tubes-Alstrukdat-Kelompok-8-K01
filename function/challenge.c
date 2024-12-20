
#include <stdio.h>
#include "challenge.h"
#include "inputUser.h"
#include "compare.h"
#include "quantumWordle.h"
#include "tebakangka.h"
#include "wordl3.h"
#include "user.h"

void challenge (int UserIndex){
    
        ArrayOfKata input;
        input = inputUser();

        /*while(input.WordCount < 2 && input.WordCount > 0){
            if (stringCompare(input.kata[0], "1")){
                if (userList[UserIndex].money < 200){
                    printf("Uang yang dimiliki kurang! Silakan kerja terlebih dahulu.");
                }
                else{
                    userList[UserIndex].money -= 200;
                    printf("Masukkan tebakanmu!\n");
                    tebakangka(UserIndex);
                }
            }
            else if (stringCompare(input.kata[0], "2")){
                if (userList[UserIndex].money < 500){
                    printf("Uang yang dimiliki kurang! Silakan cari challenge lain atau kerja terlebih dahulu.");
                }
                else{
                    userList[UserIndex].money-=500;
                    wordl3(UserIndex);
                }
            }
            else if (stringCompare(input.kata[0], "3")){
                if (userList[UserIndex].money < 600){
                    printf("Uang yang dimiliki kurang! Silakan cari challenge lain atau kerja terlebih dahulu.");
                }
                else {
                    userList[UserIndex].money-=600;
                    quantumWordle(UserIndex);
                }
            }
            ArrayOfKata input = inputUser();
        }*/
       while (1) {
        input = inputUser(); // Dapatkan input dari user
        if (input.WordCount == 0) { // Jika input kosong, keluar
            printf("Input kosong, keluar dari challenge.\n");
            break;
        }

        if (stringCompare(input.kata[0], "1")) {
            if (userList[UserIndex].money < 200) {
                printf("Uang yang dimiliki kurang! Silakan kerja terlebih dahulu.\n");
            } else {
                userList[UserIndex].money -= 200;
                printf("Masukkan tebakanmu!\n");
                tebakangka(UserIndex);
            }
        } else if (stringCompare(input.kata[0], "2")) {
            if (userList[UserIndex].money < 500) {
                printf("Uang yang dimiliki kurang! Silakan cari challenge lain atau kerja terlebih dahulu.\n");
            } else {
                userList[UserIndex].money -= 500;
                wordl3(UserIndex);
            }
        } else if (stringCompare(input.kata[0], "3")) {
            if (userList[UserIndex].money < 600) {
                printf("Uang yang dimiliki kurang! Silakan cari challenge lain atau kerja terlebih dahulu.\n");
            } else {
                userList[UserIndex].money -= 600;
                quantumWordle(UserIndex);
            }
        } else {
            printf("Pilihan tidak valid, coba lagi.\n");
        }
    }
}
