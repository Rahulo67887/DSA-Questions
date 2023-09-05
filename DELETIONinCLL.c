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

void DELfromBEG(){
    temp=tail->next;
    tail->next=temp->next;
    free(temp);
    printf("\nList after deletion from beginning-\n");
    display();
}

void DELfromEND(){
    struct node*current, *previous;
    current=tail->next;

    while(current!=tail){
        previous=current;
        current=current->next;
    }

    previous->next=tail->next;
    tail=previous;
    free(current);

    printf("\nList after deletion from end-\n");
    display();
}

void DELfromPOS(){
    int pos=0,i=1,length=0;
     struct node*current;
    printf("From which position do you want to delete?\n");
    scanf("%d", &pos);

    temp=tail->next;
    do{
        length++;
        temp=temp->next;
    }while(temp!=tail->next);

    if(pos>length || pos<1){
        printf("Invalid Position!");
    }
    else if(pos==1){
        DELfromBEG();
    }
    else if(pos==length){
        DELfromEND();
    }
    else{
        temp=tail->next;
        while(i<pos){
            current=temp;
            temp=temp->next;
            i++;
        }
        current->next=temp->next;
        free(temp);

        printf("\nList after deletion-\n");
        display();
    }
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
    DELfromBEG();
    printf("\n");
    DELfromEND();
    printf("\n");
    DELfromPOS();
    return 0;
}