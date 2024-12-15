#include "tebakangka.h"

void tebakangka(){
    int kesempatan = 0; 

    int randomNum = generateRandomNumber(0,100);
    int uang; 

    while (kesempatan < 10){
        int tebakan; 
        scanf("%d", &tebakan);

        if (tebakan > randomNum){
            printf("Tebakanmu lebih besar!\n");
        }
        else if (tebakan < randomNum){
            printf("Tebakanmu lebih kecil!\n");
        }
        else {
            uang = 550 - (50*(kesempatan+1));
            printf("Tebakanmu benar! %d rupiah telah ditambahkan ke akun anda.\n", uang);
            break;
        }
        kesempatan++;
    }

    if (kesempatan > 9){
        printf("Maaf kesempatanmu sudah habis.\n");
    }
}