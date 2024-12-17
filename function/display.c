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
    " __  _   ____  _____ ____  __ __                ",     
    "|  l/ | /    T/ ___/l    j|  T  T               ",    
    "|  ' / Y  o  (   \\_  |  T |  l  |             ",     
    "|    \\ |     |\\__  T |  | |  _  |           ",     
    "|     Y|  _  |/  \\ | |  | |  |  |              ",     
    "|  .  ||  |  |\\    | j  l |  |  |            ",     
    "l__j\\_jl__j__j \\___j|____jl__j__j                ",
};

void welcome_menu()
{   
    for (int i = 0; i < sizeof(ascii_art) / sizeof(ascii_art[0]); i++) {
        delay(40,'m');
        printf("%s\n", ascii_art[i]);
}
    delay(1.8,'s');
    printf("\n");
    printf("START\n");
    delay(0.2,'s');
    printf("LOAD \n");
    delay(0.2,'s');
    printf("HELP\n");
    delay(0.2,'s');
    printf("QUIT\n");
    delay(0.2,'s');
}

void keluar_game(){
    for (int i = 0; i < sizeof(ascii_art1) / sizeof(ascii_art1[0]); i++) {
        delay(50,'m');
        printf("%s\n", ascii_art1[i]);
    }
}

void login_help(boolean isLogin)
{
    if(!isLogin){
        delay(50,'m');
        printf("HELP MENU PURRMART===============================\n");
        printf("REGISTER : melakukan pendaftaran akun baru      \n");
        printf("LOAD<spasi><filename> : menggunakan data yang telah disimpan,      \n");
        printf("LOGIN : masuk ke dalam akun dan memulai sesi    \n");
        printf("QUIT : keluar dari program                      \n");
    }
    else{
        delay(200,'m');
        printf("MENU HELP PURRMART===============================\n");
        printf("WORK : bekerja                                   \n");
        printf("WORK CHALLENGE : mengerjakan challenge           \n");
        printf("STORE lIST : melihat barang-barang di toko       \n");
        printf("STORE REQUEST : meminta penambahan barang        \n");
        printf("STORE SUPPLY : menambahkan barang dari permintaan\n");
        printf("STORE REMOVE  : menghapus barang                 \n");
        printf("LOGOUT : keluar dari sesi                        \n");
        printf("SAVE : menyimpan state ke dalam file             \n");
        printf("QUIT : keluar dari program                       \n");
    }
}

void loadingScreen(int duration) {
    char spinner[] = {'|', '/', '-', '\\'};
    int spinner_size = sizeof(spinner) / sizeof(spinner[0]);
    int elapsed_time = 0;

    while (elapsed_time < duration) {
        for (int i = 0; i < spinner_size; i++) {
            printf("\rLoading... %c                                                               ", spinner[i]); // \r returns to the beginning of the line
            fflush(stdout);                       // Force output to the terminal
            delay(100,'m');
            elapsed_time += 10;
        }
    }
    printf("\n");
}