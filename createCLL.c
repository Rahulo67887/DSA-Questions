#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
}*temp, *tail, *newnode;

void display(struct node *tail){
    temp=tail->next;

    do{
        printf("%d\n", temp->data);
        temp=temp->next;
    }while(temp!=tail->next);

}

int main(){
    int choice=1;
    tail=0;
    while(choice){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &newnode->data);
    newnode->next=0;

    if(tail==0){
        tail=newnode;
        tail->next=newnode;
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

    return 0;
}