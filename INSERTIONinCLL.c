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
    }while(temp!=tail->next);

}

void createCLL(){
    int choice=1;
    tail=0;

    while(choice){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data-");
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
    display(tail);
    //return(tail);

}

void insertATbeg(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("What do you want to insert at the beginning?\n");
    scanf("%d", &newnode->data);
    newnode->next=0;

    if(tail==0){
        tail=newnode;
        newnode->next=newnode;
    }
    else{
        newnode->next=(tail)->next;
        (tail)->next=newnode;
    }

    printf("\nList after insertion at beginning-\n");
    display(tail);
}

void insertATend(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("What do you want to insert at the end?\n");
    scanf("%d", &newnode->data);
    newnode->next=0;

    if(tail==0){
        tail=newnode;
        newnode->next=newnode;
    }
    else{
        newnode->next=(tail)->next;
        (tail)->next=newnode;
        tail=newnode;
    }

    printf("\nList after insertion at end-\n");
    display(tail);
}

void insertATpos(){
    int pos=0,i=1,length=0;
    newnode=(struct node*)malloc(sizeof(struct node));
    
    temp=(tail)->next;
    do{
        temp=temp->next;
        length++;
        
    }while(temp!=(tail)->next);
    
    printf("At which position do you want to insert?\n");
    scanf("%d", &pos);

    if(pos>length){
        printf("Invalid Position!");
    }
    else if(pos==1){
        insertATbeg();
    }
    else if(pos==length){
        insertATend();
    }
    else{
        printf("What do you want to insert?\n");
        scanf("%d", &newnode->data);
        newnode->next=0;
        temp=(tail)->next;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }

    printf("\nList after insertion-\n");
    display(tail);
}

int main(){
    createCLL();
    printf("\n");
    insertATbeg();
    printf("\n");
    insertATend();
    printf("\n");
    insertATpos();
    return 0;
}