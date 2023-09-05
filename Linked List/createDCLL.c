#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*prev, *next;
}*newnode, *tail, *head, *temp;

void display(){
    temp=head;
    do{
        printf("%d\n", temp->data);
        temp=temp->next;
    }while(temp!=tail->next);
}

int main(){
    head=0;
    int choice=1;

    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &newnode->data);

        if(head==0){
            head=tail=newnode;
            head->prev=head;
            head->next=head;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            newnode->next=head;
            head->prev=newnode;
            tail=newnode;
        }

        printf("Do you want to continue?(press '1' for 'yes' and '0' for 'no'):");
        scanf("%d", &choice);
    }

    printf("\nYour List-\n");
    display();
    return 0;
}