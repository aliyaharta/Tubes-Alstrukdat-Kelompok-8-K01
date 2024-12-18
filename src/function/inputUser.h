#ifndef input_User
#define input_User
#include "config.h"

typedef struct ArrayOfKata{
    char kata[WordMax][CharMax];
    int WordCount;
} ArrayOfKata;

void CopyString(char dest[], char src[]);

ArrayOfKata inputUser();

#endif