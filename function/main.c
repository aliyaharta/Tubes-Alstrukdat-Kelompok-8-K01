#include "display.h"
#include "inputUser.h"
#include "boolean.h"
#include <stdio.h>

int main (){

    welcome_menu();
    ArrayOfKata inputkata;
    do{ printf(">> ");
        inputkata = inputUser();
        printf("%d\n",inputkata.Length);
    }
    while(inputkata.Length!=1);
    return 0;
}