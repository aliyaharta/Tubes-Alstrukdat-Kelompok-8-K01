#ifndef STACK_H
#define STACK_H

#include "boolean.h"

#define MAX_STACK 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];  // Nama barang
    int totalPrice;           // Total harga
} StackElement;

typedef struct {
    StackElement items[MAX_STACK];
    int top;                  // Indeks elemen teratas
} Stack;

// Fungsi dasar stack
void CreateEmptyStack(Stack *stack);
boolean IsStackEmpty(Stack stack);
boolean IsStackFull(Stack stack);
void Push(Stack *stack, char *name, int totalPrice);
void Pop(Stack *stack, StackElement *element);
void DisplayStack(Stack stack, int angka);

#endif
