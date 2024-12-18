#ifndef SETMAP_H
#define SETMAP_H

#include "config.h"
#include "boolean.h"
#include "copystr.h"
#include "./../function/compare.h"
// #include "barang.h"

#define MAX_CART 100
#define CART_NOT_FOUND -999

typedef struct {
    char Name[WordMax];
	int Quantity;
} CartItems;

typedef struct {
	CartItems Items[MAX_CART];
	int Count;
} SetMap;

void createEmptyCart(SetMap *cart);
int findCartItem(SetMap cart, const char *name);
boolean isEmptyCart(SetMap cart);
boolean isFullCart(SetMap cart);


#endif