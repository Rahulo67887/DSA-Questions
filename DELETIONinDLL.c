#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*prev;
    struct node*next;
};

struct node *temp, *head, *tail, *newnode;

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

void DELfromBEG(struct node**head){
    if(*head==0){
        printf("List is empty");
    }
    else{
        temp=*head;
        *head=(*head)->next;
        (*head)->prev=0;
        free(temp); 
    }
    
    printf("\nList after deletion from beginning-\n");
    display(*head);
}

void DELfromEND(struct node**tail){
    if(*tail==0){
        printf("List is empty");
    }
    else{
        temp=*tail;
        (*tail)->prev->next=0;
        *tail=(*tail)->prev;
        free(temp);
    }

    printf("List after deletion from end-\n");
}

void DELfromPOS(struct node**head){
    int pos, i=1, length=0;
    temp=*head;
    while(temp!=0){
        temp=temp->next;
        length++;
    }

    printf("Which node do you want to delete?\n");
    scanf("%d", &pos);
    if(length<pos){
        printf("INVALID POSITION!");
    }
    else{
        temp=*head;
        while(i<pos){
            temp=temp->next;
            i++;
        }
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        free(temp);
        printf("\nList after Deletion-\n");
        display(*head);
    }
    
}

int main(){
    createlist();
    printf("\n");
    DELfromBEG(&head);
    printf("\n");
    DELfromEND(&tail);
    display(head);
    printf("\n");
    DELfromPOS(&head);
    return 0;
}