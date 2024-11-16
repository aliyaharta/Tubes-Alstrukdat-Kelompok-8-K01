#include <stdio.h>
#include "boolean.h"

void welcome_menu()
{
    printf(" __    __    ___  _         __   ___   ___ ___    ___      ______   ___  ");
    printf("|  T__T  T  /  _]| T       /  ] /   \ |   T   T  /  _]    |      T /   \ ");
    printf("|  |  |  | /  [_ | |      /  / Y     Y| _   _ | /  [_     |      |Y     Y");
    printf("|  |  |  |Y    _]| l___  /  /  |  O  ||  \_/  |Y    _]    l_j  l_j|  O  |");
    printf("l  `  '  !|   [_ |     T/   \_ |     ||   |   ||   [_       |  |  |     |");
    printf(" \      / |     T|     |\     |l     !|   |   ||     T      |  |  l     !");
    printf("  \_/\_/  l_____jl_____j \____j \___/ l___j___jl_____j      l__j   \___/ ");
    printf("                                                                         ");     
    printf("                                                                         ");                                                                
    printf(" ____  __ __  ____   ____   ___ ___   ____  ____  ______  __             ");             
    printf("|    \|  T  T|    \ |    \ |   T   T /    T|    \|      T|  T            ");          
    printf("|  o  )  |  ||  D  )|  D  )| _   _ |Y  o  ||  D  )      ||  |            "); 
    printf("|   _/|  |  ||    / |    / |  \_/  ||     ||    /l_j  l_j|__j            ");       
    printf("|  |  |  :  ||    \ |    \ |   |   ||  _  ||    \  |  |   __             ");   
    printf("|  |  l     ||  .  Y|  .  Y|   |   ||  |  ||  .  Y |  |  |  T            ");    
    printf("l__j   \__,_jl__j\_jl__j\_jl___j___jl__j__jl__j\_j l__j  l__j            ");
    printf("                                                                         ");
    printf("1. START : Untuk memulai sesi baru                                       ");
    printf("2. LOAD : Untuk memulai sesi berdasarkan file konfigurasi                ");
    printf("3. HELP : Untuk memberikan info selanjutnya                              ");
    printf("4. QUIT : Untuk keluar dari program                                      ");
}

void login_help()
{
    printf("=============WELCOME TO HELP MENU PURRMART===============");
    printf("1. REGITSER : Untuk melakukan pendaftaran akun baru      ");
    printf("2. LOGIN : Untuk masuk ke dalam akun dan memulai sesi    ");
    printf("3. QUIT : Untuk keluar dari program                      ");
}

void main_menu(){
    printf("=====================MENU HELP PURRMART===================");
    printf("1. WORK : Untuk bekerja                                   ");
    printf("2. WORK CHALLENGE : Untuk mengerjakan challenge           ");
    printf("3. STORE lIST : Untuk melihat barang-barang di toko       ");
    printf("4. STORE REQUEST : Untuk meminta penambahan barang        ");
    printf("5. STORE SUPPLY : Untuk menambahkan barang dari permintaan");
    printf("6. STORE REMOVE  : Untuk menghapus barang                 ");
    printf("7. LOGOUT : Untuk keluar dari sesi                        ");
    printf("8. SAVE : Untuk menyimpan state ke dalam file             ");
    printf("9. QUIT : Untuk keluar dari program                       ");
}