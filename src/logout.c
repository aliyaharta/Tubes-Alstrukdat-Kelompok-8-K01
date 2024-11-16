#include <stdio.h>
#include "user.h"
#include "baca_kata.h"
#include "boolean.h"

void logout(User user_main)
{
    Word perintah;
    printf("Apakah anda ingin logout dari game (Y/N) ?\n");
    baca_kata(perintah,2); 

    if (perintah.TabWord[0] == 'Y'||perintah.TabWord[0] == 'y')
    {
        printf("Terima kasih telah bermain %s\n",user_main.name);
        return true;
    }
    else if (perintah.TabWord[0] == 'N' || perintah.TabWord[0] == 'n')
    {
        printf("oke gajadi logout\n");
        return false;
    }
    else
    {
        printf("perintah salah, masukkan yang benar");
        return logout(user_main);
    }  
}