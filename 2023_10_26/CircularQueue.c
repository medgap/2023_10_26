#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 5

typedef struct Queue{
    int front;
    int rear;
    int data[MAXSIZE];
}Queue;

Queue* initQueue(){
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    Q->front = 0;
    Q->rear = 0;
    return Q;
}

int isFull(Queue* Q){
    if((Q->rear + 1) % MAXSIZE == Q->front)
        return 1;
    return 0;
}

int isEmpty(Queue* Q){
    if(Q->rear == Q->front){
        return 1;
    }
    return 0;
}

int enQueue(Queue* Q,int data){
    if(isFull(Q)){
        return 0;
    }
    else{
        Q->data[Q->rear] = data;
        Q->rear = (Q->rear + 1) % MAXSIZE;
        return 1;
    }
}

int deQueue(Queue* Q){
    if(isEmpty(Q)){
        return 0;
    }
    else{
        int data = Q->data[Q->front];
        Q->front = (Q->front + 1) % MAXSIZE;
    }
}

void PrintQueue(Queue* Q){
    int length = (Q->rear - Q->front +MAXSIZE) % MAXSIZE;
    int index = Q->front;
    for (int i = 0; i < length; i++)
    {
        printf("%d->",Q->data[index]);
        index = (index + 1) % MAXSIZE;
    }
    printf("NULL\n");
}

int main(){
    Queue* q = initQueue();
    enQueue(q,1);
    enQueue(q,2);
    enQueue(q,3);
    enQueue(q,4);
    enQueue(q,5);
    PrintQueue(q);
    deQueue(q);
    deQueue(q);
    PrintQueue(q);
    return 0;
}