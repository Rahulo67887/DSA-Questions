#include <stdio.h>
#include<stdlib.h>

#define N 5
int queue[N];
int rear=-1;
int front=-1;

void enque(int x){
    if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else if(front==(rear+1)%N){
        printf("Queue is full");
    }
    else{
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}

void deque(){
    if(front==-1 && rear==-1){
        printf("Queue is empty");
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        printf("Dequed element is %d\n", queue[front]);
        front=(front+1)%N;
    }
}

void peek(){
    printf("First element is %d\n", queue[front]);
}

void display(){
    int i=front;
    do{
        printf("%d\n", queue[i]);
        i=(i+1)%N;
    }while(i!=(rear+1)%N);
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