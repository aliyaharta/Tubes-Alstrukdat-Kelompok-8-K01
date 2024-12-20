#include <stdio.h>
#include "queue.h"

Queue antrian;

void createQueue(Queue *antrian) {
    antrian->head = IDX_UNDEF;
    antrian->tail = IDX_UNDEF;
}

boolean isEmpty(Queue antrian) {
    return antrian.head == IDX_UNDEF && antrian.tail == IDX_UNDEF;
}

boolean isFull(Queue antrian) {
    return (antrian.tail + 1) % MAX_QUEUE_SIZE == antrian.head;
}

void enqueue(Queue *antrian, char *item) {
    if (isEmpty(*antrian)) {
        antrian->head = 0;
    }

    antrian->tail = (antrian->tail + 1) % MAX_QUEUE_SIZE;
    copyString(antrian->items[antrian->tail], item);
}

void dequeue(Queue *antrian, char *item) {
    copyString(item, antrian->items[antrian->head]);

    if (antrian->head == antrian->tail) {
        antrian->head = -1;
        antrian->tail = -1;
    } else {
        antrian->head = (antrian->head + 1) % MAX_QUEUE_SIZE;
    }
}

boolean inQueue(Queue antrian, char *item) {
    if (isEmpty(antrian)) {
        return false;
    }

    int i = antrian.head;
    do {
        if (stringCompare(antrian.items[i], item)) {
            return true;
        }
        i = (i + 1) % MAX_QUEUE_SIZE;
    } while (i != (antrian.tail + 1) % MAX_QUEUE_SIZE);

    return false;
}