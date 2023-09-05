#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*prev;
    struct node*next;
};

struct node *temp, *head, *tail, *newnode, *nextnode, *currentnode;

void display(struct node*head){
    temp=head;
    while(temp!=0){
        printf("%d\n", temp->data);
        temp=temp->next;
    }
}

struct node *createlist(){
    int choice=1;
    head=tail=0;

    while(choice){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &newnode->data);
    newnode->next=newnode->prev=0;

    if(head==0){
        head=tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }

    printf("Do you want to continue?(press '1' for 'yes' and '0' for 'no'):");
    scanf("%d", &choice);
    }

    printf("\n");
    printf("YOUR LIST-\n");
    display(head);
}

void reverse(struct node**head, struct node**tail){
    currentnode=*head;
    while(currentnode!=0){
        nextnode=currentnode->next;
        currentnode->next=currentnode->prev;
        currentnode->prev=nextnode;
        currentnode=nextnode;
    }
    currentnode=*head;
    *head=*tail;
    *tail=currentnode;
    printf("REVERSED LIST-\n");
    display(*head);
}

int main(){
    createlist();
    printf("\n");
    reverse(&head, &tail);
    return 0;
}