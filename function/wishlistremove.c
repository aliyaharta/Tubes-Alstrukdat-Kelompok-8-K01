#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include "inputUser.h"
#include "compare.h"
#include "combineword.h"

void wishlist_remove(LinkedList *wishlist) {
    ArrayOfKata nama;
    printf("Masukkan nama barang yang ingin diremove :\n");
    nama = inputUser();

    char input[CharMax];

    combineword(input,nama);

    if (wishlist->size == 0) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        return;
    }

    Node *current = wishlist->head;
    Node *prev = NULL;

    while (current != NULL) {
        // Membandingkan nama barang 
        
        //if (list_compare_strings(current->data, name) == 0) {
        if (stringCompare(current->data, input)){
            if (prev == NULL) { 
                wishlist->head = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            wishlist->size--;
            printf("%s berhasil dihapus dari WISHLIST!\n", input);
            return;
        }

        prev = current;
        current = current->next;
    }

    // Jika barang tidak ditemukan
    printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n", input);
}


// int main() {
//     LinkedList wishlist;
//     list_create(&wishlist);
//  
//     list_insert_last(&wishlist, "Barang1");
//     list_insert_last(&wishlist, "Barang2");
//     list_insert_last(&wishlist, "Barang3");
//    
//     printf("Wishlist sebelum penghapusan:\n");
//     list_print(wishlist);
//     
//     wishlist_remove(&wishlist, "Barang2");
//     
//     printf("Wishlist setelah penghapusan:\n");
//     list_print(wishlist);
//    
//     wishlist_remove(&wishlist, "Barang4");
//   
//     list_destroy(&wishlist);

//     return 0;
// }
