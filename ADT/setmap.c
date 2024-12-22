#include <stdio.h>
#include "setmap.h"

void createEmptyCart(SetMap *cart){
    cart->Count = 0;
}

int findCartItem(SetMap cart, const char *name){
    for (int i = 0; i < cart.Count; i++){
        if(stringCompare(cart.Items[i].Name, name)){ 
            return i;
        }
    }
    return CART_NOT_FOUND;
}

boolean isEmptyCart(SetMap cart){
    return (cart.Count == 0);
}

boolean isFullCart(SetMap cart){
    return (cart.Count == MAX_CART);
}
