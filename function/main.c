#include <stdio.h>
#include "display.h"
#include "inputUser.h"
#include "boolean.h"
#include "compare.h"

int main (){
    boolean isExit = false;

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    welcome_menu();
    ArrayOfKata inputkata;
    while(!isExit){
        do{ printf(">> ");
            inputkata = inputUser();
        }
        while(inputkata.Length!=1);
        
        if (stringCompare(inputkata.kata[0], "QUIT")){
            printf("\n\nKamu keluar dari PURRMART.\nDadah ^_^/\n\n");
            delay(250);
            keluar_game();
            isExit = true;
        }
        else if(stringCompare(inputkata.kata[0], "HELP")){
            login_help();
            printf("\n");

        }
    }

    return 0;
}