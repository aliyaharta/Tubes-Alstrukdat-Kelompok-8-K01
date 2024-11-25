#include <stdio.h>
#include "delay.h"

void delay(int milliseconds) {
    volatile long long count = 0;
    long long target = milliseconds * 1000000LL;  // Calibrate this value to your system

    while (count < target) {
        count++;
    }
}
