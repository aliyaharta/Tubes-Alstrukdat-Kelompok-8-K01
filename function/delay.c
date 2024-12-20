#include <stdio.h>
#include "delay.h"
#include <time.h>

void delay(int duration, char unit) {
    if (unit == 's') {
        time_t start_time = time(NULL); // Get current time
        while (time(NULL) < start_time + duration) {
            // Wait until the desired time has passed
        }
    } else if (unit == 'm') { // 'm' for milliseconds
        clock_t start_time = clock(); // Get current clock ticks
        // Convert milliseconds to clock ticks
        clock_t wait_ticks = (duration * CLOCKS_PER_SEC) / 1000;
        while ((clock() - start_time) < wait_ticks) {
            // Wait until the desired number of clock ticks has passed
        }
    } else {
        // Invalid unit
        printf("Invalid unit. Use 's' for seconds or 'm' for milliseconds.\n");
    }
}