#include "data.h"

void login_help()
{
    if(!loggedIn){
        printf("=============WELCOME TO HELP MENU PURRMART===============\n");
        printf("1. REGITSER : Untuk melakukan pendaftaran akun baru      \n");
        printf("2. LOGIN : Untuk masuk ke dalam akun dan memulai sesi    \n");
        printf("3. QUIT : Untuk keluar dari program                      \n");
    }
    else{
        printf("=====================MENU HELP PURRMART===================\n");
        printf("1. WORK : Untuk bekerja                                   \n");
        printf("2. WORK CHALLENGE : Untuk mengerjakan challenge           \n");
        printf("3. STORE lIST : Untuk melihat barang-barang di toko       \n");
        printf("4. STORE REQUEST : Untuk meminta penambahan barang        \n");
        printf("5. STORE SUPPLY : Untuk menambahkan barang dari permintaan\n");
        printf("6. STORE REMOVE  : Untuk menghapus barang                 \n");
        printf("7. LOGOUT : Untuk keluar dari sesi                        \n");
        printf("8. SAVE : Untuk menyimpan state ke dalam file             \n");
        printf("9. QUIT : Untuk keluar dari program                       \n");
    }
}
