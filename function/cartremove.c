#include <stdio.h>
#include "cartremove.h"

void removecartitems(SetMap *cart, char *name, int quantity){
    int index = findCartItem(*cart,name);

    if(index==CART_NOT_FOUND){
        printf("Barang tidak ada di keranjang belanja\n");
        return; 
    }
    else{
        if(quantity > cart->Items[index].Quantity){
            printf("Tidak berhasil mengurangi, hanya terdapat %d %s pada keranjang\n",cart->Items[index].Quantity,cart->Items[index].Name);
        }
        else{
            cart->Items[index].Quantity = cart->Items[index].Quantity - quantity;
            if (cart->Items[index].Quantity == 0){
                for(int i = index; i<cart->Count-1;i++){
                    cart->Items[i]=cart->Items[i+1];
                }
                cart->Count = cart->Count - 1;
            }
            printf("Berhasil mengurangi %d %s dari keranjang belanja\n",quantity, name);
        }
    }
}
