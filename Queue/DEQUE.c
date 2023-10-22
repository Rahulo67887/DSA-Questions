#include <stdio.h>
#include<stdlib.h>

#define N 5
int r=-1,f=-1;
int deque[N];

void enquefront(int x){
    if((f==r+1)||(f==0 && r==N-1)){
        printf("Queue is full\n");
    }
    else if(f==-1 && r==-1){
        f=r=0;
        deque[f]=x;
    }
    else if(f==0){
        f=N-1;
        deque[f]=x;
    }
    else{
        f--;
        deque[f]=x;
    }
}

void enquerear(int x){
    if((f==r+1)||(f==0&& r==N-1)){
        printf("Queue is full\n");
    }
    else if(f==-1 && r==-1){
        f=r=0;
        deque[r]=x;
    }
    else if(r==N-1){
        r=0;
        deque[r]=x;
    }
    else{
        r++;
        deque[r]=x;
    }
}

void dequerear(){
    if(f==-1 && r==-1){
        printf("Queue is empty\n");
    }
    else if(f==r){
        printf("Dequed element is %d\n", deque[r]);
        f=r=-1;
    }
    else if(r==0){
        printf("Dequed element id %d\n", deque[r]);
        r=N-1;
    }
    else{
        printf("Dequed element id %d\n", deque[r]);
        r--;
    }
}

void dequefront(){
    if(f==-1 && r==-1){
        printf("queue is empty\n");
    }
    else if(f==r){
        printf("Dequed element id %d\n", deque[f]);
        f=r=-1;
    }
    else if(f==N-1){
        printf("Dequed element id %d\n", deque[f]);
        f=0;
    }
    else{
        printf("Dequed element id %d\n", deque[f]);
        f++;
    }
}

void display(){
    if(f==-1 && r==-1){
        printf("Queue is empty\n");
    }
    else{
        int i=f;
        do{
            printf("%d\n", deque[i]);
            i=(i+1)%N;
        }while(i!=r);
        printf("%d\n", deque[i]);
    }
}

int main(){
    enquefront(7);
    enquefront(9);
    enquefront(6);
    enquefront(3);
    enquerear(4);
    enquerear(1);
    enquerear(0);
    display();
    return 0;
}