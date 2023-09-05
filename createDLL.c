#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*prev;
    struct node*next;
};

struct node *temp, *newnode, *head;

void display(struct node*head){
    temp=head;
    while(temp!=0){
        printf("%d\n", temp->data);
        temp=temp->next;
    }
}

void createDoubleList(){
    head=0;
    int choice=1;
    
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &newnode->data);
        newnode->next=newnode->prev=0;

        if(head==0){
            head=temp=newnode;
        }
        else{
            newnode->prev=temp;
            temp->next=newnode;
            temp=newnode;
        }

        printf("Do you want to continue?(press '1' for 'yes' and '0' for 'no'):");
        scanf("%d", &choice);
    }
    printf("\n");
    printf("Your list-\n");
    display(head);
}


int main(){
    createDoubleList();
    return 0;
}