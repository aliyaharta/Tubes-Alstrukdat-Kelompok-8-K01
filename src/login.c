#include <stdio.h>
#include "user.h"
#include "mesinkata.h"
#include "list_user.h"

int login (ListUser *lu){
    Word username;
    Word password;
    
    boolean islogin = false;

    printf("Input username kamu :\n");
    scanf("%s",username.TabWord);
    username.Length = stringLen(username.TabWord);
    
    printf("Input password kamu :\n");
    scanf("%s",password.TabWord);
    password.Length = stringLen(password.TabWord);

    int userIndex = FindUser(*lu,&username);
    if(!islogin){
        if(userIndex != -1){
            if(IsPasswordEqual(&(lu->users[userIndex]),&password)){
                printf("Selamat login berhasil user %s\n", lu->users[userIndex].name);
                islogin = true;
                return(userIndex);
            }
            else{
                printf("Password salah, coba input lagi. \n");
            }
        }
        else{
            printf("Akun kamu tidak terdaftar, coba registrasi dulu\n");
        }
        return -1;
    }
}
int main(){
    ListUser lu;
    lu.count = 0;

    User u1 = {"Alice","password123",1000};
    User u2 = {"Bob","securepass",2000};

    AddUser(&lu,u1);
    AddUser(&lu,u2);

    login(&lu);
}