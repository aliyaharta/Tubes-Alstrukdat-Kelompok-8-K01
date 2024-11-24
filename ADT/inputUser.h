#ifndef input_User
#define input_User
#include "config.h"

typedef struct ArrayOfKata{
    char kata[NMax][CharMax];
    int Length;
} ArrayOfKata;

ArrayOfKata inputUser();



#endif