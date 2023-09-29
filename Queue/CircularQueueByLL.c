#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

struct node*front=0;
struct node*rear=0;

void enque(int x){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;

    if(front==0 && rear==0){
        front=rear=newnode;
        rear->next=front;
    }
    else{
        rear->next=newnode;
        rear=newnode;
        rear->next=front;  
    }
}

void deque(){
    struct node*temp=front;
    if(front==0 && rear==0){
        printf("Queue is empty");
    }
    else if(front==rear){
        printf("Dequed element is %d\n", front->data);
        front=rear=0;
        free(temp);
    }
    else{
        printf("Dequed element is %d\n", front->data);
        front=front->next;
        free(temp);
    }
}

void peek(){
    if(front==0 && rear==0){
        printf("Queue is empty");
    }
    else{
        printf("First element is %d\n", front->data);
    }
}

void display(){
    struct node*temp=front;

    if(front==0 && rear==0){
        printf("Queue is empty");
    }
    else{
        while(temp->next!=front){
            printf("%d\n", temp->data);
            temp=temp->next;
        }
        printf("%d\n", temp->data);
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