#include "delay.h"

void delay(int seconds) {
    time_t start = time(NULL);
    while (time(NULL) - start < seconds);
}
