#include <stdio.h>
#include "setmap.h"

// create empty cart for user
void createEmptyCart(SetMap *cart){
    cart->Count = 0;
}

// find item in cart
int findCartItem(SetMap cart, const char *name){
    for (int i = 0; i < cart.Count; i++){
        if(stringCompare(cart.Items[i].Name, name)){ 
            return i;
        }
    }
    return CART_NOT_FOUND;
}

// check if cart is empty
boolean isEmptyCart(SetMap cart){
    return (cart.Count == 0);
}

// check if cart is full
boolean isFullCart(SetMap cart){
    return (cart.Count == MAX_CART);
}
