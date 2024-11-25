#ifndef LIST_USER_H
#define LIST_USER_H

#include "user.h"
#define MAX_USER 100

typedef struct {
    User users[MAX_USER];
    int count;
} ListUser;

void CreateListUser(ListUser *lu);
void AddUser(ListUser *lu, User u);
void DisplayUsers(ListUser lu);
int FindUser(ListUser lu, const Word *username);

#endif