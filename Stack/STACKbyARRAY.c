#include <stdio.h>
#include<stdlib.h>

#define N 5
int stack[N];
int top=-1;

void display(){
    if(top==-1){
        printf("Stack is empty");
    }
    for(int i=top; i>=0; i--){
        printf("%d\n", stack[i]);
    }
}

void push(){
    int x;
    printf("Enter data-");
    scanf("%d", &x);

    if(top==N-1){
        printf("overflow");
    }
    else{
        top++;
        stack[top]=x;
    }
}

void pop(){
    if(top==-1){
        printf("underflow");
    }
    else{
        top--;
        printf("Stack after popping-\n");
        display();
    }
}

void peek(){
    if(top==-1){
        printf("Stack is empty");
    }
    else{
        printf("%d\n", stack[top]);
    }
}

int main(){
    int ch;

    do{
        printf("Enter choice- 1 for push, 2 for pop, 3 for peek, 4 for display, 0 for exit:");
        scanf("%d", &ch);

        switch(ch){
            case 1: push();
            break;

            case 2: pop();
            break;

            case 3: peek();
            break;

            case 4: printf("\nStack-\n");
            display();

            case 0:;
            break;
            
            default:printf("invalid position");
        }
    }while(ch!=0);
    
    return 0;
}