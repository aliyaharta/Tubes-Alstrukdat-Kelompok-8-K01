#include <stdio.h>
#include "delay.h"

void delay(int seconds) {
    time_t start_time = time(NULL);
    while (time(NULL) - start_time < seconds);
}
