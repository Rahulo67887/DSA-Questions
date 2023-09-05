#include <stdio.h>
#include<stdlib.h>
int main(){

    struct node{
        int data;
        struct node*next;
    };

    struct node  *head, *newnode, *temp;
    head=0;
    int choice;

    while(choice){
        newnode=(struct node *)malloc(sizeof(struct node));

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

        printf("Do you want to continue?(press'0' for 'no' amd '1' for 'yes'):");
        scanf("%d", &choice);
    }

    temp=head;

    printf("\n");

    while(head!=0){
        printf("%d\n", temp->data);
        temp=temp->next;
    }
    return 0;
}