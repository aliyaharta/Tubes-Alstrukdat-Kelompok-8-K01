#ifndef LIST_USER_H
#define LIST_USER_H

#include "user.h"
#define MAX_USER 100

typedef struct {
    char name[100];
    char password[100];
    int money;
} User;

typedef struct {
    User items[100];
    int size;
} ListUser;

void CreateListUser(ListUser *lu);
void AddUser(ListUser *lu, User u);
void DisplayUsers(ListUser lu);
int FindUser(ListUser lu, const Word *username);

#endif