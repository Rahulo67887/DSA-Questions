#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

struct node *top=0;

void display(){
    struct node *temp=top;

    if(top==0){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack is-\n");
        while(temp!=0){
        printf("%d\n", temp->data);
        temp=temp->next;
    }
    }
}

void push(int x){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=top;
    top=newnode;
}

void peek(){
    if(top==0){
        printf("Stack is empty\n");
    }
    else{
        printf("Top element is %d\n", top->data);
    }
}

void pop(){
    struct node*temp=top;

    if(top==0){
        printf("Stack is empty\n");
    }
    else{
        printf("Popped element is %d\n", top->data);
        top=top->next;
        free(temp);
    }
}

int main(){
    push(5);
    push(6);
    push(89);
    push(76);
    display();

    pop();
    peek();
    pop();
    peek();
    display();
    return 0;
}