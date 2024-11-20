#ifndef input_User
#define input_User
#include "config.h"

typedef struct ArrayOfKata{
    char kata[5][100];
    int Length;
} ArrayOfKata;

ArrayOfKata inputUser();



#endif