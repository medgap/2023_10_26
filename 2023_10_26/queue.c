#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* initQueue(){
    Node* Q = (Node*)malloc(sizeof(Node));
    Q->data = 0;
    Q->next = NULL;
    return Q;
}

void enQueue(Node* Q,int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    Node* q = Q;
    for(int i = 0; i < Q->data; i++){
        q = q->next;
    }
    node->next = q->next;
    q->next = node;
    Q->data++;
}

int isEmpty(Node* Q){
    if(Q->data == 0 || Q->next == NULL)
        return 1;
    return 0;
}

int deQueue(Node* Q){
    if(isEmpty(Q)){
        return 0;
    }
    else{
        Node* node = Q->next;
        int res = node->data;
        Q->next = node->next;
        Q->data--;
        free(node);
        return res;
    }
}

void PrintQueue(Node* Q){
    Node* q = Q->next;
    while(q){
        printf("%d->",q->data);
        q = q->next;
    }
    printf("NULL\n");
}

int main(){
    Node* node = initQueue();
    enQueue(node,1);
    enQueue(node,2);
    enQueue(node,3);
    enQueue(node,4);
    enQueue(node,5);

    PrintQueue(node);

    deQueue(node);
    deQueue(node);
    deQueue(node);
    deQueue(node);
    PrintQueue(node);

    return 0;

}