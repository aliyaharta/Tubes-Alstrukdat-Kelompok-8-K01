#include "data.h"

boolean endProgram;
boolean loggedIn;
boolean validcommand;
int money = 0;
Word new_password;
Word new_username;

void kondisi_awal(){
    endProgram = false;
    loggedIn = false;
    validcommand = true;
}