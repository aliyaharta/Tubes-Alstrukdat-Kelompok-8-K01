#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk membuat LinkedList kosong
void list_create(LinkedList *list) {
    list->head = NULL;
    list->size = 0;
}

// Fungsi untuk menghancurkan LinkedList dan membebaskan memori
void list_destroy(LinkedList *list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
    list->size = 0;
}

// Fungsi untuk menambahkan elemen di akhir LinkedList
int list_insert_last(LinkedList *list, const char *data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        return 0; // Gagal karena tidak cukup memori
    }

    for (int i = 0; i < MAX_LEN; i++) {
        new_node->data[i] = data[i];
        if (data[i] == '\0') break;
    }
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    list->size++;
    return 1; // Berhasil
}

// Fungsi untuk mendapatkan panjang LinkedList
int list_length(const LinkedList list) {
    return list.size;
}

// Fungsi untuk mendapatkan node pada posisi tertentu
Node *list_get_node(const LinkedList list, int position) {
    if (position <= 0 || position > list.size) {
        return NULL; // Posisi tidak valid
    }

    Node *current = list.head;
    for (int i = 1; i < position; i++) {
        current = current->next;
    }
    return current;
}

// Fungsi untuk mencetak isi LinkedList
void list_print(const LinkedList list) {
    Node *current = list.head;
    int index = 1;
    while (current != NULL) {
        printf("%d. %s\n", index++, current->data);
        current = current->next;
    }
}

// Fungsi untuk membandingkan dua string tanpa string.h
int list_compare_strings(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}
