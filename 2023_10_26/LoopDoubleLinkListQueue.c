#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
    int data;
    struct Node* next;
    struct Node* pre;
}Node;

Node* initQueue(){
    Node* Q = (Node*)malloc(sizeof(Node));
    Q->data = 0;
    Q->next = Q;
    Q->pre = Q;
    return Q;
}



void enQueue(Node* Q,int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;

    node->next = Q;
    node->pre = Q->pre;
    Q->pre->next = node;
    Q->pre = node;
    

    Q->data++;
}

int isEmpty(Node* Q){
    if(Q->data == 0 || Q->next == Q)
        return 1;
    return 0;
}

int deQueue(Node* Q){
    Node* node = Q->next;
    if(isEmpty(Q)){
        return 0;
    }
    else{
        int res = node->data;
        
        //Q->next = node->next;
        Q->next = Q->next->next;

        
        //node->next->pre = Q;
        Q->next->pre = Q;
        Q->data--;
        //free(node);
        return res;
    }
}

void PrintQueue(Node* Q){
    Node* q = Q->next;
    while(q != Q){
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

    deQueue(node);
    deQueue(node);
    
    PrintQueue(node);
    return 0;
}