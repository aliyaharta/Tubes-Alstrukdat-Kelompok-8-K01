#ifndef CARTADD_H
#define CARTADD_H

#include "setmap.h"
#include "inputUser.h"
#include "barang.h"
#include "compare.h"

//add barang ke cart
void addcart(SetMap *cart, ListBarang barangList, char *name, int quantity);

#endif