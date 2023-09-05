#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
}*temp, *tail, *newnode;

void display(){
    temp=tail->next;
    do{
        printf("%d\n", temp->data);
        temp=temp->next;
    }
    while(temp!=tail->next);
}

void reverseCLL(){
    struct node*nextnode, *current, *prev;
    current=tail->next;
    nextnode=current->next;

    if(tail==0){
        printf("Empty List");
    }
    else if(tail==current){
        printf("There's only one node in the list");
    }
    else{
        while(current!=tail){
            prev=current;
            current=nextnode;
            nextnode=current->next;
            current->next=prev;
    }
    }
    nextnode->next=tail;
    tail=nextnode;
    
    printf("Reversed link-\n");
    display();
}

void createCLL(){
    tail=0;
    int choice=1;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &newnode->data);
        newnode->next=0;

        if(tail==0){
            tail=newnode;
            newnode->next=newnode;
        }
        else{
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }

        printf("Do you want to continue?(press '1' for 'yes' and '0' for 'no'):");
        scanf("%d", &choice);
    }

    printf("\nYour List-\n");
    display();
}


int main(){
    createCLL();
    printf("\n");
    reverseCLL();
    return 0;
}