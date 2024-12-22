#include "wishlistclear.h"
#include <stdio.h>
#include <stdlib.h>

void wishlist_clear(LinkedList *wishlist) {
    if (wishlist->size == 0) {
        printf("Wishlist sudah kosong.\n");
        return;
    }

    Node *current = wishlist->head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    wishlist->head = NULL;
    wishlist->size = 0;

    printf("Wishlist telah dikosongkan.\n");
}


// int main() {
//     LinkedList wishlist;
//     list_create(&wishlist);

//     list_insert_last(&wishlist, "Barang1");
//     list_insert_last(&wishlist, "Barang2");
//     list_insert_last(&wishlist, "Barang3");

//     printf("Wishlist sebelum dikosongkan:\n");
//     list_print(wishlist);

//     wishlist_clear(&wishlist);

//     printf("Wishlist setelah dikosongkan:\n");
//     list_print(wishlist);

//     return 0;
// }
