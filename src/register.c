#include <stdio.h>
#include "list_user.h"
#include "mesinkata.h"
#include "user.h"

void register_user(ListUser *lu)
{
    boolean regis = false;
    Word new_username;
    Word new_password;
    User u;
    int user_index;
    int money = 0;


    while (!regis) {
        printf("Masukkan username baru kamu (minimal 1 karakter):\n");
        scanf("%s", new_username.TabWord);
        new_username.Length = stringLen(new_username.TabWord);

        if (new_username.Length == 0) {
            printf("Username tidak boleh kosong. Coba isi lagi\n");
        } else {
            user_index = FindUser(*lu, &new_username);
            if (user_index != -1) {
                printf("Username sudah digunakan, silahkan coba username lain\n");
            } else {
                regis = true;
                printf("Username '%s' berhasil didaftarkan\n", new_username.TabWord);
            }
        }
    }

    regis = false;
    while (!regis) {
        printf("Masukkan password baru kamu (minimal 4 karakter): ");
        scanf("%s", new_password.TabWord);
        new_password.Length = stringLen(new_password.TabWord);
        
        if (new_password.Length == 0) {
            printf("Password tidak boleh kosong. Coba ulang password anda.\n");
        } else if (new_password.Length < 4) {
            printf("Password harus lebih dari 4 karakter. Coba ulang password anda.\n");
        } else {
            regis = true;
            printf("Password berhasil dibuat\n");
        }
    }

    CreateUser(&u, &new_username, &new_password, money);
    AddUser(lu, u);
}

int main(){
    ListUser lu;
    lu.count = 0;

    User u1 = {"Alice","password123",1000};
    User u2 = {"Bob","securepass",2000};

    AddUser(&lu,u1);
    AddUser(&lu,u2);

    register_user(&lu);

    printf("\nList of registered users:\n");
    for (int i = 0; i < lu.count; i++) {
        printf("Username: %s, Password: %s, Money: %d\n", lu.users[i].name, lu.users[i].password, lu.users[i].money);
    }
    return 0;
}