#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node*front=0;
struct node*rear=0;

void enque(int x){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;

    if(front==0 && rear==0){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

void deque(){
    if(front==0 && rear==0){
        printf("Underflow");
    }
    else{
        struct node*temp=front;
        printf("Dequed element is %d\n", front->data);
        front=front->next;
        free(temp);
    }
}

void display(){
    if(front==0 && rear==0){
        printf("Underflow");
    }
    else{
        struct node*temp=front;
        while(temp!=0){
            printf("%d\n", temp->data);
            temp=temp->next;
        }
    }
}

void peek(){
    if(front==0 && rear==0){
        printf("Underflow");
    }
    else{
        printf("First element is %d\n", front->data);
    }
}

int main(){
    enque(2);
    enque(-1);
    enque(5);
    enque(0);
    display();
    peek();
    printf("\n");
    deque();
    printf("\n");
    peek();
    display();
    return 0;
}