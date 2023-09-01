#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*prev;
    struct node*next;
};

struct node*head, *tail, *newnode, *temp;

void display(struct node*head){
    struct node*temp=head;

    while(temp!=0){
        printf("%d\n", temp->data);
        temp=temp->next;
    }
}

struct node *createlist(){
    head=0,tail=0;
    int choice=1;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data-");
        scanf("%d", &newnode->data);
        newnode->next=newnode->prev=0;
        
        if(head==0){
            head=tail=newnode;
        }
        else{
            newnode->prev=tail;
            tail->next=newnode;
            tail=newnode;
        }

        printf("Do you want to continue?(press '1' for 'yes' and '0' for 'no'):");
        scanf("%d", &choice);
    }

    printf("\n");
    printf("Your list-\n");
    display(head); 

    return head;
}

void insertingATbeg(struct node**head){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("What do you want to insert at the beginning?\n");
    scanf("%d", &newnode->data);
    newnode->next=newnode->prev=0;

    if(*head==0){
        printf("EMPTY LIST!");
    }
    else{
        (*head)->prev=newnode;
        newnode->next=*head;
        *head=newnode;
    }

    printf("\n");
    printf("List after insertion at the beginning-\n");
    display(*head);
}

void insertingATend(struct node**head, struct node**tail){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("What do you want to insert at the end?\n");
    scanf("%d", &newnode->data);
    newnode->next=newnode->prev=0;

    newnode->prev=*tail;
    (*tail)->next=newnode;
    *tail=newnode;

    printf("\n");
    printf("List after inserting at the end-\n");
    display(*head);
}

void insertingATpos(struct node**head){
    int pos, i=1, length=0;
    printf("At which position do you want to insert?\n");
    scanf("%d", &pos);
    temp=*head;

    while(temp!=0){
        temp=temp->next;
        length++;
    }

    if(pos>length){
        printf("invalid position!");
    }
    else{
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("What do you want to insert?\n");
        scanf("%d", &newnode->data);
        newnode->next=newnode->prev=0;

        temp=*head;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }

        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->next->prev=newnode;

        printf("\n");
        printf("List after insertion-\n");
        display(*head);
    }
}

int main(){
    head=createlist();
    printf("\n");
    insertingATbeg(&head);
    printf("\n");
    insertingATend(&head, &tail);
    printf("\n");
    insertingATpos(&head);
    return 0;
}