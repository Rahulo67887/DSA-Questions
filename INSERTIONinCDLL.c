#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*prev;
    struct node*next;
    }*newnode, *temp, *tail, *head;

void display(){
    temp=head;
    do{
        printf("%d\n", temp->data);
        temp=temp->next;
    }while(temp!=tail->next);
}

void createCDLL(){
    head=0;
    int choice=1;

    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &newnode->data);

        if(head==0){
            head=tail=newnode;
            head->next=newnode;
            head->prev=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            newnode->next=head;
            head->prev=tail;
            tail=newnode;
        }

        printf("Do you want to continue?(press '1' for 'yes' and '0' for 'no'):");
        scanf("%d", &choice);
    }

    printf("\nYour List-\n");
    display();
}


void insertionATbeg(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("What do you want to insert at the beginning?\n");
    scanf("%d", &newnode->data);

    if(head==0){
        head=tail=newnode;
        head->next=newnode;
        head->prev=newnode;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        newnode->prev=tail;
        tail->next=head;
    }

    printf("List after insertion at beginning-\n");
    display();
}

void insertionATend(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("What do you want to insert at the end?\n");
    scanf("%d", &newnode->data);

    if(head==0){
        head=tail=newnode;
        head->next=newnode;
        head->prev=newnode;
    }
    else{
        newnode->prev=tail;
        tail->next=newnode;
        newnode->next=head;
        tail=newnode;
        head->prev=tail;
    }

    printf("List after insertion at end-\n");
    display();
}

void insertionATpos(){
    int pos=0, i=1, length;
    printf("At which position do you want to insert?\n");
    scanf("%d", &pos);

    temp=head;
    do{
        length++;
        temp=temp->next;
    }while(temp!=tail->next);

    if(length+1<pos || pos<1){
        printf("Invalid position!");
    }
    else if(pos==1){
        insertionATbeg();
    }
    else if(pos==length+1){
        insertionATend();
    }
    else{
        temp=head;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("What do you want to insert?\n");
        scanf("%d", &newnode->data);
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
    }

    printf("List after insertion-\n");
    display();
}

int main(){
    createCDLL();
    printf("\n");
    insertionATbeg();
    printf("\n");
    insertionATend();
    printf("\n");
    insertionATpos();
    return 0;
}