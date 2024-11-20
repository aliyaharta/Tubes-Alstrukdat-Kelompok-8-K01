#include <stdio.h>
#include "user.h"
#include "list_user.h"
#include "boolean.h"

void logout()
{
    char perintah;
    boolean logout = false;
    
    while(!logout){
        printf("Apakah anda ingin logout dari game (Y/N) ?\n");
        scanf("%s",&perintah);
        if (perintah == 'Y'||perintah == 'y')
        {
            printf("Terima kasih telah bermain");
            logout = true;
        }
        else if (perintah== 'N' || perintah== 'n')
        {
            printf("Oke gajadi logout\n");
            break;
        }
        else
        {
            printf("Perintah salah, masukkan yang benar\n");
        }
    }  
}

int main(){
    logout();
}