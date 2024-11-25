#include <stdio.h>
#include "delay.h"
#include "display.h"
#include "boolean.h"

const char *ascii_art[] = {
    " __    __    ___  _         __   ___   ___ ___    ___      ______   ___  ",
    "|  T__T  T  /  _]| T       /  ] /   \\ |   T   T  /  _]    |      T /   \\ ",
    "|  |  |  | /  [_ | |      /  / Y     Y| _   _ | /  [_     |      |Y     Y",
    "|  |  |  |Y    _]| l___  /  /  |  O  ||  \\_/  |Y    _]    l_j  l_j|  O  |",
    "l  `  '  !|   [_ |     T/   \\_ |     ||   |   ||   [_       |  |  |     |",
    " \\      / |     T|     |\\     |l     !|   |   ||     T      |  |  l     !",
    "  \\_/\\_/  l_____jl_____j \\____j \\___/ l___j___jl_____j      l__j   \\___/ ",
    " ____  __ __  ____   ____   ___ ___   ____  ____  ______  __             ",             
    "|    \\|  T  T|    \\ |    \\ |   T   T /    T|   \\ |      T|  T            ",     
    "|  o  )  |  ||  D  )|  D  )| _   _ |Y  o  ||  D  )      ||  |            ",
    "|   _/|  |  ||    / |    / |  \\_/  ||     ||    /l_j  l_j|__j            ", 
    "|  |  |  :  ||    \\ |    \\ |   |   ||  _  ||    \\  |  |   __             ",   
    "|  |  l     ||  .  Y|  .  Y|   |   ||  |  ||  .  Y |  |  |  T            ",  
    "l__j   \\__,_jl__ \\_jl__ \\_jl___j___jl__j__jl__ \\ _jl__j  l__j            \n",

    "by Ambil ber(k)as"
};

const char *ascii_art1[] = {
    " ______    ___  ____   ____  ___ ___   ____                                       ",     
    "|      T  /  _]|    \\ l    j|   T   T /    T                                      ",    
    "|      | /  [_ |  D  ) |  T | _   _ |Y  o  |                                      ",     
    "l_j  l_jY    _]|    /  |  | |  \\_/  ||     |                                      ",     
    "  |  |  |   [_ |    \\  |  | |   |   ||  _  |                                      ",     
    "  |  |  |     T|  .  Y j  l |   |   ||  |  |                                      ",     
    "  l__j  l_____jl__j\\_j|____jl___j___jl__j__j                                      ",     
    "                                                                                   ",
    " __  _   ____  _____ ____  __ __       _____ __ __  ___     ____  __ __           ",     
    "|  l/ | /    T/ ___/l    j|  T  T     / ___/|  T  T|   \\   /    T|  T  T          ",    
    "|  ' / Y  o  (   \\_  |  T |  l  |    (   \\_ |  |  ||    \\ Y  o  ||  l  |          ",     
    "|    \\ |     |\\__  T |  | |  _  |     \\__  T|  |  ||  D  Y|     ||  _  |          ",     
    "|     Y|  _  |/  \\ | |  | |  |  |     /  \\ ||  :  ||     ||  _  ||  |  |          ",     
    "|  .  ||  |  |\\    | j  l |  |  |     \\    |l     ||     ||  |  ||  |  |          ",     
    "l__j\\_jl__j__j \\___j|____jl__j__j      \\___j \\__,_jl_____jl__j__jl__j__j          ",         
    "                                                                                   ",
    " ___ ___    ___  ____    ____   ____  __ __  ____    ____  __  _   ____  ____     ", 
    "|   T   T  /  _]|    \\  /    T /    T|  T  T|    \\  /    T|  l/ ] /    T|   \\     ",
    "| _   _ | /  [_ |  _  YY   __jY   __j|  |  ||  _  YY  o  ||  ' / Y  o  ||  _  Y    ",
    "|  \\_/  |Y    _]|  |  ||  T  ||  T  ||  |  ||  |  ||     ||    \\ |     ||  |  |    ",
    "|   |   ||   [_ |  |  ||  l_ ||  l_ ||  :  ||  |  ||  _  ||     Y|  _  ||  |  |    ",
    "|   |   ||     T|  |  ||     ||     |l     ||  |  ||  |  ||  .  ||  |  ||  |  |    ",
    "l___j___jl_____jl__j__jl___,_jl___,_j \\__,_jl__j__jl__j__jl__j\\_jl__j__jl__j__j\n  ",
    "                                                                                   ",
    " ____  __ __  ____   ____   ___ ___   ____  ____  ______                           ",
    "|    \\|  T  T|    \\ |    \\ |   T   T /    T|    \\|      T                          ",
    "|  o  )  |  ||  D  )|  D  )| _   _ |Y  o  ||  D  )      |                          ",
    "|   _/|  |  ||    / |    / |  \\_/  ||     ||    /l_j  l_j                          ",
    "|  |  |  :  ||    \\ |    \\ |   |   ||  _  ||    \\  |  |                            ",
    "|  |  l     ||  .  Y|  .  Y|   |   ||  |  ||  .  Y |  |                            ",
    "l__j   \\__,_jl__j\\_jl__j\\_jl___j___jl__j__jl__j\\_j l__j                            ",
};

void welcome_menu()
{   
    for (int i = 0; i < sizeof(ascii_art) / sizeof(ascii_art[0]); i++) {
        delay(200);
        printf("%s\n", ascii_art[i]);
}
    delay(600);
    printf("\n");
    printf("\n");
    printf("1. START : Untuk memulai sesi baru                                       \n");
    delay(1);
    printf("2. LOAD : Untuk memulai sesi berdasarkan file konfigurasi                \n");
    delay(1);
    printf("3. HELP : Untuk memberikan info selanjutnya                              \n");
    delay(1);
    printf("4. QUIT : Untuk keluar dari program                                      \n");
    delay(1);
    printf("\n");
    delay(1);
}

void keluar_game(){
    for (int i = 0; i < sizeof(ascii_art1) / sizeof(ascii_art1[0]); i++) {
        delay(240);
        printf("%s\n", ascii_art1[i]);
    }
}

void login_help(boolean isLogin)
{
    if(!isLogin){
        delay(200);
        printf("=============WELCOME TO HELP MENU PURRMART===============\n");
        printf("1. REGISTER : Untuk melakukan pendaftaran akun baru      \n");
        printf("2. LOGIN : Untuk masuk ke dalam akun dan memulai sesi    \n");
        printf("3. QUIT : Untuk keluar dari program                      \n");
    }
    else{
        delay(200);
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
