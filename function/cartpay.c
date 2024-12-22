#include <stdio.h>
#include "cartpay.h"
#include "cartshow.h"
#include "inputUser.h"
#include "compare.h"
#include "user.h"
#include "cartremove.h"
#include "combineword.h"

void cartpay (SetMap *cart, ListBarang barangList, Stack *history, int userIndex){
    if(isEmptyCart(*cart)){
        printf("Keranjang belanja kosong.\n");
    }
    else{
        int totalcost = 0;
        int maxpriceindex = 0; 
        int indexbarangmax = 0;
        for(int i = 0; i<cart->Count ; i++){
            int indexbarang = findItemBarang(barangList,cart->Items[i].Name);
            int currentTotalPrice = cart->Items[i].Quantity * barangList.items[indexbarang].price;
            int maxTotalPrice = cart->Items[maxpriceindex].Quantity * barangList.items[indexbarangmax].price;
            if (currentTotalPrice > maxTotalPrice) {
                maxpriceindex = i;
                indexbarangmax = indexbarang;
            }
            else if (currentTotalPrice == maxTotalPrice) {
                if (stringCompare(cart->Items[i].Name, cart->Items[maxpriceindex].Name) > 0) {
                    maxpriceindex = i;
                    indexbarangmax = indexbarang;
                }
            }
        }
        for (int i = 0; i < cart->Count; i++) {
            int indexbarang = findItemBarang(barangList, cart->Items[i].Name);
            totalcost += cart->Items[i].Quantity * barangList.items[indexbarang].price;
        }
        printf("Kamu akan membeli : \n");
        showcartitems(*cart);
        printf("Total biaya yang harus dikeluarkan adalah %d, apakah jadi beli ? (YA/TIDAK)\n",totalcost);
        ArrayOfKata input = inputUser();

        if(stringCompare(input.kata[0],"YA")){
            if(userList[userIndex].money >= totalcost){
                userList[userIndex].money -= totalcost;
                printf("Selamat kamu telah membeli barang-barang tersebut.\n");
                Push(history,cart->Items[maxpriceindex].Name,barangList.items[indexbarangmax].price);
                cart->Count = 0;
            }
            else{
                printf("Maaf uang kamu tidak cukup.\n");
            }
        }
        else if(stringCompare(input.kata[0],"TIDAK")){
            printf("Okay, kembali ke menu utama");
        }
        else{
            printf("Berikan input yang valid\n");
        }

    }
}