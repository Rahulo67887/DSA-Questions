#include <stdio.h>
#include<stdlib.h>

#define N 5
int queue[N];
int front =-1;
int rear=-1;

void enque(int x){
    if(rear==N-1){
        printf("Overflow");
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}

void deque(){
    if(front==-1 && rear==-1){
        printf("Underflow");
    }
    else if(front==rear){
        printf("Dequed element is %d\n", queue[front]);
        front=rear=-1;
    }
    else{
        printf("Dequed element is %d\n", queue[front]);
        front++;
    }
}

void display(){
    if(front==-1 && rear==-1){
        printf("Underflow");
    }
    else {
        printf("Queue-\n");
        for(int i=front; i<=rear; i++){
            printf("%d\n" ,queue[i]);
        }
    }
}

void peek(){
    if(front==-1 && rear==-1){
        printf("Underflow");
    }
    else{
        printf("First element is %d\n", queue[front]);
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