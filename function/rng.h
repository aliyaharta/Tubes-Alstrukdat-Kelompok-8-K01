#ifndef RNG_H
#define RNG_H

#include "time.h"
/* 
I.S: min dan max telah diberikan sebagai batas bawah dan batas atas untuk bilangan acak yang diinginkan.
F.S: Menghasilkan bilangan acak dalam rentang [min, max] dan mengembalikan nilainya.
*/
int generateRandomNumber(int min, int max);

#endif