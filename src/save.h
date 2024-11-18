#ifndef SAVE_H
#define SAVE_H

#include "list_barang.h" // Header untuk ListBarang
#include "list_user.h"   // Header untuk ListUser

int SAVE(const char *filename, ListBarang *barangList, ListUser *userList);

#endif
