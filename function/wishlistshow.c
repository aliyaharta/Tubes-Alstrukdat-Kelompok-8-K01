#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

void wishlist_show(const LinkedList *wishlist) {
    if (wishlist->size == 0) {
        printf("Wishlist kamu kosong!\n");
        return;
    }

    printf("Berikut adalah isi wishlist-mu:\n");
    Node *current = wishlist->head;
    int index = 1;

    while (current != NULL) {
        printf("%d %s\n", index++, current->data);
        current = current->next;
    }
}



// int main() {
//     LinkedList wishlist;
//     list_create(&wishlist);

//     list_insert_last(&wishlist, "Barang1");
//     list_insert_last(&wishlist, "Barang2");
//     list_insert_last(&wishlist, "Barang3");

//     wishlist_show(&wishlist);
//     list_destroy(&wishlist);
//     wishlist_show(&wishlist);

//     return 0;
// }

