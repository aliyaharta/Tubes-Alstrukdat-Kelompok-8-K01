#include "user.h"
#include <stdio.h>

void CreateUser_Username(User *u, const Word *name, const Word *password, int money) {
    for (int i = 0; i < name->Length && i < MAX_LEN - 1; i++) {
        u->name[i] = name->TabWord[i];
    }
    u->name[name->Length] = '\0';

    u->money = money;

}
void CreateUser_Password(User *u, const Word *name, const Word *password, int money) {
    for (int i = 0; i < password->Length && i < MAX_LEN - 1; i++) {
        u->password[i] = password->TabWord[i];
    }
    u->password[password->Length] = '\0';
    // cek 
}

void DisplayUser(User u) {
    printf("Name: %s, Money: %d\n", u.name, u.money);
}

boolean IsUsernameEqual(User *u, const Word *username) {
    for (int i = 0; i < username->Length; i++) {
        if (i >= MAX_LEN || username->TabWord[i] != u->name[i]) {
            return false;
        }
    }
    return (username->Length == 0 || u->name[username->Length] == '\0');
}