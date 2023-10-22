#include <stdio.h>
#include<stdlib.h>

#define N 5
int s1[N], s2[N];
int top1=-1, top2=-1;
int count=0;

void push1(int data){
    if(top1==N-1){
        printf("Queue overflow\n");
    }
    else{
        top1++;
        s1[top1]=data;
    }
}

void push2(int data){
    if(top2==N-1){
        printf("Queue overflow\n");
    }
    else{
        top2++;
        s2[top2]=data;
    }
}

int pop1(){
    return s1[top1--];
}

int pop2(){
    return s2[top2--];
}

void enque(int x){
    push1(x);
    count++;
} 

void deque(){
    if(top1==-1 && top2==-1){
        printf("Queue overflow\n");
    }
    else{
        for(int i=0; i<count; i++){
            int a=pop1();
            push2(a);
        }
    printf("dequed element is %d\n", pop2());
    count--;
    for(int i=0; i<count; i++){
        int b=pop2();
        push1(b);
    }
    }
}

void display(){
    for(int i=0; i<=top1; i++){
        printf("%d\n", s1[i]);
    }
}

int main(){
    enque(8);
    enque(9);
    enque(7);
    enque(5);
    deque();
    deque();
    enque(6);
    display();
    return 0;
}