#ifndef DATA_H
#define DATA_H

// #include ADT lah 
#include "ADT/boolean.h"
#include "ADT/user.h"

// extern digunakan untuk definisiin variabel tp yg ada di file lain
extern boolean endProgram; 
extern boolean loggedIn;
extern boolean validcommand;
extern Word new_username;
extern Word new_password;
extern int money; 

void kondisi_awal();

#endif