#include <stdio.h>
#include "data.h"
#include "mesinkata.h"
#include "user.h"


void register_user()
{
    while (!loggedIn){
        printf("Masukkan username baru kamu (minimal 1 karakter) : ");
        baca_kata(new_username,MAX_LEN);
        if (&new_username.Length==0)
        {
            printf("Username tidak boleh kosong. Coba isi lagi\n");
        }
        else // cek availability username dulu
        {
            printf("Username '%s' berhasil didaftarkan \n",new_username);
            CreateUser_Username(&user_baru,&new_username);
            loggedIn = false;
        }
    }
    while(!loggedIn){
        printf("Masukkan password baru kamu (minimal 4 karakter): ");
        baca_kata(new_password,MAX_LEN);
        if(&new_password.Length==0)
        {
            printf("Password tidak boleh kosong. Coba ulang password anda.");
        }
        else if (new_password.Length<4)
        {
            printf("Password haru lebih dari 4 karakter. Coba ulang password anda.");
        }
        else
        {
            loggedIn = false;
            printf("Password berhasil dibuat");
            CreateUser_Password(&user_baru,&new_password,money);
        }
    }
}