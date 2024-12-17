#include <stdio.h>
#include "challenge.h"
#include "inputUser.h"
#include "compare.h"

void challenge (){
        int angka;

        ArrayOfKata input = inputUser();

        while(input.WordCount < 2 && input.WordCount > 0){
            if (stringCompare(input.kata[0], "1")){
                if (money < 200){
                    printf("Uang yang dimiliki kurang! Silakan kerja terlebih dahulu.");
                }
                else{
                    money -= 200;
                    printf("Masukkan tebakanmu!\n");
                    tebakangka();
                }
            }
            else if (stringCompare(input.kata[0], "2")){
                if (money < 500){
                    printf("Uang yang dimiliki kurang! Silakan cari challenge lain atau kerja terlebih dahulu.");
                }
                else{
                    money-=500;
                    wordl3();
                }
            }
            else if (stringCompare(input.kata[0], "3")){
                if (money < 600){
                    printf("Uang yang dimiliki kurang! Silakan cari challenge lain atau kerja terlebih dahulu.");
                }
                else {
                    money-=600;
                    quantumWordle();
                }
            }
            ArrayOfKata input = inputUser();
        }
}
