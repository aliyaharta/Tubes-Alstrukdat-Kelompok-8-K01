#include <stdio.h>
#include <time.h>
#include "data.h"

void delay(){
    clock_t start_time = clock();
    while (clock()<start_time+100000);
}

void welcome_menu()
{
    delay();
    printf(" __    __    ___  _         __   ___   ___ ___    ___      ______   ___  \n");
    delay();
    printf("|  T__T  T  /  _]| T       /  ] /   \ |   T   T  /  _]    |      T /   \ \n");
    delay();
    printf("|  |  |  | /  [_ | |      /  / Y     Y| _   _ | /  [_     |      |Y     Y\n");
    delay();
    printf("|  |  |  |Y    _]| l___  /  /  |  O  ||  \_/  |Y    _]    l_j  l_j|  O  |\n");
    delay();
    printf("l  `  '  !|   [_ |     T/   \_ |     ||   |   ||   [_       |  |  |     |\n");
    delay();
    printf(" \      / |     T|     |\     |l     !|   |   ||     T      |  |  l     !\n");
    delay();
    printf("  \_/\_/  l_____jl_____j \____j \___/ l___j___jl_____j      l__j   \___/ \n");
    delay();
    printf("                                                                         \n");     
    delay();
    printf("                                                                         \n");          
    delay();                                                      
    printf(" ____  __ __  ____   ____   ___ ___   ____  ____  ______  __             \n");    
    delay();         
    printf("|    \|  T  T|    \ |    \ |   T   T /    T|    \|      T|  T            \n");         
    delay(); 
    printf("|  o  )  |  ||  D  )|  D  )| _   _ |Y  o  ||  D  )      ||  |            \n"); 
    delay();
    printf("|   _/|  |  ||    / |    / |  \_/  ||     ||    /l_j  l_j|__j            \n");    
    delay();   
    printf("|  |  |  :  ||    \ |    \ |   |   ||  _  ||    \  |  |   __             \n");   
    delay();
    printf("|  |  l     ||  .  Y|  .  Y|   |   ||  |  ||  .  Y |  |  |  T            \n");    
    delay();
    printf("l__j   \__,_jl__j\_jl__j\_jl___j___jl__j__jl__j\_j l__j  l__j            \n");
    delay();
    printf("                                                                         \n");
    delay();
    printf("                                                                         \n");
    delay();
    printf("1. START : Untuk memulai sesi baru                                       \n");
    delay();
    printf("2. LOAD : Untuk memulai sesi berdasarkan file konfigurasi                \n");
    delay();
    printf("3. HELP : Untuk memberikan info selanjutnya                              \n");
    delay();
    printf("4. QUIT : Untuk keluar dari program                                      \n");
    delay();
    printf("\n");
    delay();
}

void keluar_game(){
    delay();
    printf(" ______    ___  ____   ____  ___ ___   ____                              \n");
    delay();                             
    printf("|      T  /  _]|    \ l    j|   T   T /    T                             \n"); 
    delay();                            
    printf("|      | /  [_ |  D  ) |  T | _   _ |Y  o  |                             \n");             
    delay();                
    printf("l_j  l_jY    _]|    /  |  | |  \_/  ||     |                             \n");         
    delay();                    
    printf("  |  |  |   [_ |    \  |  | |   |   ||  _  |                             \n");   
    delay();                          
    printf("  |  |  |     T|  .  Y j  l |   |   ||  |  |                             \n");                 
    delay();            
    printf("  l__j  l_____jl__j\_j|____jl___j___jl__j__j                             \n"); 
    delay();                            
    printf("                                                                         \n");        
    delay();                
    printf(" __  _   ____  _____ ____  __ __      ______    ___  _       ____  __ __ \n");
    delay();
    printf("|  l/ ] /    T/ ___/l    j|  T  T    |      T  /  _]| T     /    T|  T  T\n");
    delay();
    printf("|  ' / Y  o  (   \_  |  T |  l  |    |      | /  [_ | |    Y  o  ||  l  |\n");
    delay();
    printf("|    \ |     |\__  T |  | |  _  |    l_j  l_jY    _]| l___ |     ||  _  |\n");
    delay();
    printf("|     Y|  _  |/  \ | |  | |  |  |      |  |  |   [_ |     T|  _  ||  |  |\n");
    delay();
    printf("|  .  ||  |  |\    | j  l |  |  |      |  |  |     T|     ||  |  ||  |  |\n");
    delay();
    printf("l__j\_jl__j__j \___j|____jl__j__j      l__j  l_____jl_____jl__j__jl__j__j\n");
    delay();
    printf("                                                                         \n");
    delay();
    printf("____     ___  ____   ___ ___   ____  ____  ____                          \n");
    delay();
    printf("|    \   /  _]|    \ |   T   T /    Tl    j|    \                        \n");
    delay();
    printf("|  o  ) /  [_ |  D  )| _   _ |Y  o  | |  T |  _  Y                       \n");
    delay();
    printf("|     TY    _]|    / |  \_/  ||     | |  | |  |  |                       \n");
    delay();
    printf("|  O  ||   [_ |    \ |   |   ||  _  | |  | |  |  |                       \n");
    delay();
    printf("|     ||     T|  .  Y|   |   ||  |  | j  l |  |  |                       \n");
    delay();
    printf("l_____jl_____jl__j\_jl___j___jl__j__j|____jl__j__j                       \n");
    delay();
}
