#ifndef RNG_H
#define RNG_H

#include "time.h"

// Function to generate a random number between min and max (inclusive)
/* 
I.S: min dan max telah diberikan sebagai batas bawah dan batas atas untuk bilangan acak yang diinginkan.
F.S: Menghasilkan bilangan acak dalam rentang [min, max] dan mengembalikan nilainya.
*/
int generateRandomNumber(int min, int max);

#endif