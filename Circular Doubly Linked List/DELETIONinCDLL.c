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


void deletionFROMbeg(){
    temp=head;

    if(head==0){
        printf("Empty List!");
    }
    else if(head->next==head){
        head=tail=0;
        free(temp);
    }
    else{
        head=head->next;
        head->prev=tail;
        tail->next=head;
        free(temp);
    }

    printf("List after deletion at beginning-\n");
    display();
}

void deletionFROMend(){
    temp=tail;

    if(head==0){
        printf("Empty List!");
    }
    else if(head->next==head){
        head=tail=0;
        free(temp);
        printf("After deletion, the list is empty.");
    }
    else{
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        free(temp);
        
        printf("List after deletion at end-\n");
        display();
    }
}

void deletionFROMpos(){
    int pos=0, i=1, length;
    printf("From which position do you want to delete?\n");
    scanf("%d", &pos);

    temp=head;
    do{
        length++;
        temp=temp->next;
    }while(temp!=tail->next);

    if(length<pos || pos<1){
        printf("Invalid position!");
    }
    else if(pos==1){
        deletionFROMbeg();
    }
    else if(pos==length){
        deletionFROMend();
    }
    else{
        temp=head;
        while(i<pos){
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        printf("\nList after deletion-\n");
        display();
    }
}

int main(){
    createCDLL();
    printf("\n");
    deletionFROMbeg();
    printf("\n");
    deletionFROMend();
    printf("\n");
    deletionFROMpos();
    printf("%d", tail->next->data);
    return 0;
}