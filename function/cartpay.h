#ifndef CARTPAY_H
#define CARTPAY_H

#include "setmap.h"
#include "barang.h"
#include "stack.h"

void cartpay (SetMap *cart, ListBarang barangList, Stack *history, int userIndex);

#endif