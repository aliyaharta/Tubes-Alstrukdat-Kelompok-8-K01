#include "list_user.h"
#include <stdio.h>

// void CreateListUser(ListUser *lu) {
//     lu->count = 0;
// }

void AddUser(ListUser *lu, User u) {
    if (lu -> count < MAX_USER) {
        lu -> users[lu -> count] = u;//debug add user
        lu -> count++;
        printf("User berhasil ditambahkan\n");
    } else {
        printf("List User penuh\n");
    }
}

// void DisplayUsers(ListUser lu) {
//     for (int i = 0; i < lu.count; i++) {
//         printf("%d. ", i + 1);
//         DisplayUser(lu.users[i]);
//     }
// }

int FindUser(ListUser lu, const Kata *username) {
    for (int i = 0; i < lu.count; i++) {
        if (IsUsernameEqual(&lu.users[i], username)) {
            return i;
        }
    }
    return -1;
}