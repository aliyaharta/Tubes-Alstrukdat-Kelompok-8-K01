#include "user.h"
#include "compare.h"

User userList[25];
int userCount = 0;

int getIndex(const char *name) {
    for (int i = 0; i < userCount; i++) {
        if (stringCompare(userList[i].name, name)) {
            return i; // Mengembalikan indeks jika ditemukan
        }
    }
    return -1; // Mengembalikan -1 jika tidak ditemukan
}