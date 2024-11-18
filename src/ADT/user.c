#include "user.h"
#include <stdio.h>

void CreateUser(User *u, const Word *name, const Word *password, int money) {
    for (int i = 0; i < name->Length && i < MAX_LEN - 1; i++) {
        u->name[i] = name->TabWord[i];
    }
    u->name[name->Length] = '\0';

    for (int i = 0; i < password->Length && i < MAX_LEN - 1; i++) {
        u->password[i] = password->TabWord[i];
    }
    u->password[password->Length] = '\0';

    u->money = money;

}

void DisplayUser(User u) {
    printf("Name: %s, Money: %d\n", u.name, u.money);
}

booleanIsUsernameEqual(User *u, const Word *username) {
    for (int i = 0; i < username->Length; i++) {
        // mengubah huruf menjadi huruf kecil semua
        char user_char = (u->name[i] >= 'A' && u->name[i] <= 'Z') ? (u->name[i] + 'a' - 'A') : u->name[i];
        char username_char = (username->TabWord[i] >= 'A' && username->TabWord[i] <= 'Z') ? (username->TabWord[i] + 'a' - 'A') : username->TabWord[i];

        if (i >= MAX_LEN || username_char != user_char) {
            return false;
        }
    }
    return (username->Length == 0 || u->name[username->Length] == '\0');
}
