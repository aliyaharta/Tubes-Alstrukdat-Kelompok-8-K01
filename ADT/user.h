#ifndef USER_H
#define USER_H

#include "config.h"

typedef struct {
    char name[WordMax];
    char password[WordMax];
    int money;
} User;

extern User userList[25];
extern int userCount;

int getIndex(const char *name);
#endif // USER_H
