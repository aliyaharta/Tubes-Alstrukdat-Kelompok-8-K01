#ifndef USER_H
#define USER_H

#include "config.h"
#include "setmap.h"
#define maxUser 25

typedef struct {
    char name[WordMax];
    char password[WordMax];
    int money;
    SetMap cart;
} User;

extern User userList[maxUser];
extern int userCount;

int getIndex(const char *name);
#endif // USER_H
