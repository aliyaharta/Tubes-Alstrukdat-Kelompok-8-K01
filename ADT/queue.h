#include <stdio.h>
#include "./../function/compare.h"
#include "copystr.h"
#include "boolean.h"

#define IDX_UNDEF -1
#define MAX_QUEUE_SIZE 100

typedef struct {
    char items[MAX_QUEUE_SIZE][50]; // Array of strings to store items in the queue
    int head;
    int tail;
} Queue;

extern Queue antrian;

void createQueue(Queue *queue);
boolean isEmpty(Queue queue);
boolean isFull(Queue queue);
void enqueue(Queue *queue, char *item);
void dequeue(Queue *queue, char *item);
boolean inQueue(Queue queue, char *item);

