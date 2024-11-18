#include <stdio.h>
#include <time.h>

void delay(int milisekon) {
    clock_t start_time = clock();
    while (clock() < start_time + milisekon * CLOCKS_PER_SEC / 1000);
}

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
    "l__j   \\__,_jl__ \\_jl__ \\_jl___j___jl__j__jl__ \\ _jl__j  l__j            ",
};

void welcome_menu()
{   
    for (int i = 0; i < sizeof(ascii_art) / sizeof(ascii_art[0]); i++) {
        delay(100);
        printf("%s\n", ascii_art[i]);
}
    printf("\n");
    printf("\n");
    printf("1. START : Untuk memulai sesi baru                                       \n");
    delay(100);
    printf("2. LOAD : Untuk memulai sesi berdasarkan file konfigurasi                \n");
    delay(100);
    printf("3. HELP : Untuk memberikan info selanjutnya                              \n");
    delay(100);
    printf("4. QUIT : Untuk keluar dari program                                      \n");
    delay(100);
    printf("\n");
    delay(100);
}
