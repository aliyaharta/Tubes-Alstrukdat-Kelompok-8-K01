#ifndef WORK_H
#define WORK_H

#include <stdio.h>

extern int money;

#define MAX_LEN 50
typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    int money;
} User;

void work();

#endif // WORK_H
