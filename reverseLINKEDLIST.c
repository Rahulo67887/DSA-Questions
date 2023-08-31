#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node*head, *temp, *newnode;

void display(struct node *head){
    temp=head;
    while(temp!=0){
        printf("%d\n", temp->data);
        temp=temp->next;
    }
}

void reverse(struct node**head){
    struct node*prevnode, *nextnode, *currentnode;
    prevnode=0;
    nextnode=currentnode=*head;
    while(nextnode!=0){
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    *head=prevnode;

    display(*head);
}

struct node *createlist(){
    head=0;
    int choice;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &newnode->data);
        newnode->next=0;

        if(head==0){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        
        printf("Do you want to continue?(press '1' for 'yes' and '0' for 'no':");
        scanf("%d", &choice);
    }

    printf("\n");
    display(head);
    return(head);
}


int main(){
    head=createlist();
    printf("\n");
    reverse(&head);
    return 0;
}