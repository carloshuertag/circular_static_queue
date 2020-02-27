/******************************************
 * circular_static_int_queue
 * @author: Carlos Huerta García
 * @description: Int queue implementation
 * ***************************************/
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

typedef int iqueueEntry;

typedef struct iQueue { 
    int rear, front;
    int size; 
    iqueueEntry *array;
} iQueue;

iQueue * createiQueue(int size){
    iQueue * queue = (iQueue*)malloc(sizeof(iQueue));
    if(queue == NULL)
        exit(1);
    queue->size = size;
    queue->rear = queue->front = - 1;
    queue->array = (iqueueEntry*)calloc(queue->size, sizeof(iqueueEntry));
    if(queue->array == NULL)
        exit(1);
    return queue;
}

bool iqueueIsEmpty(iQueue * queue) {
    return queue->front == -1 || queue == NULL;
}

bool iqueueIsFull(iQueue * queue) {
    return (queue->front == 0 && queue->rear == queue->size - 1) || (queue->rear == (queue->front - 1) % (queue->size - 1));
}

void ienQueue(iqueueEntry item, iQueue * queue) {
    if(!iqueueIsFull(queue)){
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

iqueueEntry iqueueFront(iQueue * queue) {
    if(iqueueIsEmpty(queue))
        return CHAR_MIN;
    return queue->array[queue->front];
}

iqueueEntry iqueueRear(iQueue * queue) {
    if(iqueueIsEmpty(queue))
        return CHAR_MIN;
    return queue->array[queue->rear];
}

iqueueEntry ideQueue(iQueue * queue) {
    if(iqueueIsEmpty(queue))
        return CHAR_MIN;
    iqueueEntry data = queue->array[queue->front];
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

void printiQueue(iQueue * queue) {
    if(iqueueIsEmpty(queue)){
        puts("[ ]");
        return;
    }
    int i;
    if(queue->rear >= queue->front){
        for (i = queue->front; i <= queue->rear; i++) 
            printf("-[%d]-", queue->array[i]);
        return;
    }
    for (i = queue->front; i < queue->size; i++) 
        printf("-[%d]-", queue->array[i]); 
    for (i = 0; i <= queue->rear; i++) 
        printf("-[%d]-", queue->array[i]);
}

void cleariQueue(iQueue * queue) {
    if(iqueueIsEmpty(queue))
        return;
    free(queue->array);
    queue->rear = queue->front = - 1;
    queue->size = 0;
}
