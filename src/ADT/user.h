#ifndef USER_H
#define USER_H

#include "mesinkata.h"
#include "ADT/cekkata.h"

#define MAX_LEN 50

typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    int money;
}User;

// Buat User baru
void CreateUser_Username(User *u, const Word *name);

void CreateUser_Password(User *u,const Word *password, int money);

// Menampilkan informasi dari user
void DisplayUser(User u);

boolean IsUsernameEqual(User *u, const Word *username);
#endif