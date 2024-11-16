#include <stdio.h>
#include "boolean.h"
#include "mesinkata.h"
#include "user.h"

void register_user(User user_baru)
{
    boolean not_login = true;
    char new_username[50];
    char new_password[50];
    int money = 0;
    while (not_login){
        printf("Masukkan username baru kamu (minimal 1 karakter) : ");
        baca_kata(new_username,50);
        if (new_username[0]=='\0')
        {
            printf("Username tidak boleh kosong. Coba isi lagi\n");
        }
        else
        {
            printf("Username '%s' berhasil didaftarkan \n",new_username);
            CreateUser_Username(&user_baru,&new_username);
            not_login = false;
        }
    }
    while(not_login){
        printf("Masukkan password baru kamu (minimal 4 karakter): ");
        baca_kata(new_password,50);
        if(new_password[0]=='\0')
        {
            printf("Password tidak boleh kosong. Coba ulang password anda.");
        }
        else
        {
            not_login = false;
            printf("Password berhasil dibuat");
            CreateUser_Password(&user_baru,&new_password,money);
        }
    }
    return (new_username,new_password);
}