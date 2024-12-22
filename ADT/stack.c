#include "stack.h"
#include <stdio.h>
#include "copystr.h"

void CreateEmptyStack(Stack *stack) {
    stack->top = -1;
}

boolean IsStackEmpty(Stack stack) {
    return stack.top == -1;
}

boolean IsStackFull(Stack stack) {
    return stack.top == MAX_STACK - 1;
}

void Push(Stack *stack, char *name, int totalPrice) {
    if (!IsStackFull(*stack)) {
        stack->top++;
        copyString(stack->items[stack->top].name, name);
        stack->items[stack->top].totalPrice = totalPrice;
    } else {
        printf("Stack penuh, tidak bisa menambahkan riwayat!\n");
    }
}

void Pop(Stack *stack, StackElement *element) {
    if (!IsStackEmpty(*stack)) {
        *element = stack->items[stack->top];
        stack->top--;
    } else {
        printf("Stack kosong, tidak ada riwayat untuk dihapus!\n");
    }
}

void DisplayStack(Stack stack, int angka) {
    if (IsStackEmpty(stack)) {
        printf("Riwayat pembelian kosong.\n");
        return;
    }

    printf("Riwayat Pembelian:\n");
    for (int i = stack.top; i >= 0; i--) {
        printf("%d",stack.top);
        printf("%s - Total Harga: %d\n", stack.items[i].name, stack.items[i].totalPrice);
    }
}
