#include <stdio.h>
#include "delay.h"
#include <time.h>

void delay(int duration, char unit) {
    if (unit == 's') {
        time_t start_time = time(NULL); 
        while (time(NULL) < start_time + duration) {
        }
    } else if (unit == 'm') { 
        clock_t start_time = clock();
        clock_t wait_ticks = (duration * CLOCKS_PER_SEC) / 1000;
        while ((clock() - start_time) < wait_ticks) {
        }
    } else {
        printf("Invalid unit. Use 's' for seconds or 'm' for milliseconds.\n");
    }
}