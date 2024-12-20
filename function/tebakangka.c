#include "tebakangka.h"
#include "rng.h"
#include "inputUser.h"
#include "compare.h"
#include "stringToInt.h"

void tebakangka(int userIndex){
    int kesempatan = 0; 

    int randomNum = generateRandomNumber(0,100);
    int uang; 

    while (kesempatan < 10){
        int tebakan; 
        ArrayOfKata input;
        input = inputUser();

        tebakan = stringToInt(input.kata[0]);

        if (tebakan > randomNum){
            printf("Tebakanmu lebih besar!\n");
        }
        else if (tebakan < randomNum){
            printf("Tebakanmu lebih kecil!\n");
        }
        else {
            uang = 550 - (50*(kesempatan+1));
            printf("Tebakanmu benar! %d rupiah telah ditambahkan ke akun anda.\n", uang);
        }
        kesempatan++;
    }

    if (kesempatan > 9){
        printf("Maaf kesempatanmu sudah habis.\n");
    }
}