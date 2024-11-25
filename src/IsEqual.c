#include <stdio.h>

boolean IsUsernameEqual(User *u, const Word *username) {
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

boolean IsPasswordEqual(User *u, const Word *password){
    int i = 0;

    while(u->password[i]!='\0'&&password->TabWord[i]!='\0'){
        if(u->password[i]!=password->TabWord[i]){
            return false;
        }
        i++;
    }
    return(u->password[i]=='\0'&&password->TabWord[i]=='\0');
}
