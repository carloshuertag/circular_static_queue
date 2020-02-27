/*****************************************
 * circular_static_char_queue
 * @author: Carlos Huerta García
 * @description: Char queue implementation
 * **************************************/
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

typedef char queueEntry;

typedef struct Queue { 
    int rear, front;
    int size; 
    queueEntry *array;
} Queue;

Queue * createQueue(int size){
    Queue * queue = (Queue*)malloc(sizeof(Queue));
    if(queue == NULL)
        exit(1);
    queue->size = size;
    queue->rear = queue->front = - 1;
    queue->array = (queueEntry*)calloc(queue->size, sizeof(queueEntry));
    if(queue->array == NULL)
        exit(1);
    return queue;
}

bool queueIsEmpty(Queue * queue) {
    return queue->front == -1 || queue == NULL;
}

bool queueIsFull(Queue * queue) {
    return (queue->front == 0 && queue->rear == queue->size - 1) || (queue->rear == (queue->front - 1) % (queue->size - 1));
}

void enQueue(queueEntry item, Queue * queue) {
    if(!queueIsFull(queue)){
        if (queue->front == -1) { 
            queue->rear = queue->front = 0; 
            queue->array[queue->rear] = item;
            return;
        }
        if (queue->rear == queue->size - 1 && queue->front != 0) { 
            queue->rear = 0; 
            queue->array[queue->rear] = item;
            return;
        }
        queue->array[++queue->rear] = item;
    }
}

queueEntry queueFront(Queue * queue) {
    if(queueIsEmpty(queue))
        return CHAR_MIN;
    return queue->array[queue->front];
}

queueEntry queueRear(Queue * queue) {
    if(queueIsEmpty(queue))
        return CHAR_MIN;
    return queue->array[queue->rear];
}

queueEntry deQueue(Queue * queue) {
    if(queueIsEmpty(queue))
        return CHAR_MIN;
    queueEntry data = queue->array[queue->front];
    queue->array[queue->front] = CHAR_MIN;
    if(queue->front == queue->rear){
        queue->front = queue->rear = -1;
        return data;
    }
    if(queue->front == queue->size - 1){
        queue->front = 0;
        return data;
    }
    queue->front++;
    return data;
}

void printQueue(Queue * queue) {
    if(queueIsEmpty(queue)){
        puts("[ ]");
        return;
    }
    int i;
    if(queue->rear >= queue->front){
        for (i = queue->front; i <= queue->rear; i++) 
            printf("-[%c]-", queue->array[i]);
        return;
    }
    for (i = queue->front; i < queue->size; i++) 
        printf("-[%c]-", queue->array[i]); 
    for (i = 0; i <= queue->rear; i++) 
        printf("-[%c]-", queue->array[i]);
}

void clearQueue(Queue * queue) {
    if(queueIsEmpty(queue))
        return;
    free(queue->array);
    queue->rear = queue->front = - 1;
    queue->size = 0;
}
