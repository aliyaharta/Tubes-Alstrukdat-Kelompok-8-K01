#include <stdio.h>
#include "boolean.h"

void welcome_menu()
{
    printf("===============SELAMAT DATANG DI PURRMART================");
    printf("1. START : Untuk memulai sesi baru                       ");
    printf("2. LOAD : Untuk memulai sesi berdasarkan file konfigurasi");
    printf("3. HELP : Untuk memberikan info selanjutnya              ");
    printf("4. QUIT : Untuk keluar dari program                      ");
}

void tampilan_welcome_menu()
{
    boolean invalid = true;
    boolean pertama_kali = true;
    while (invalid) 
    {
        if(!pertama_kali)
        {
            printf("Masukkan invalid\n");
        }
        pertama_kali = false;
        welcome_menu();
    }
}