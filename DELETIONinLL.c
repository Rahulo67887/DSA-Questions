#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
}*head,*temp,*newnode;

void display(){
    temp=head;
    while(temp!=0){
        printf("%d\n", temp->data);
        temp=temp->next;
    }
}

void createlist(){
    head=0;
    int choice;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
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

        printf("Do you want to continue?(press '1' for 'yes' and '0' for 'no':");
        scanf("%d", &choice);
    }
    printf("\n");
    printf("YOUR LIST-\n");
    display();   
}

void delfrombeg(){
    if(head==0){
        printf("Empty list!\n");
    }
    else{
        temp=head;
        head=(head)->next;
        free(temp);
    }
    printf("List after deleting  from beginning-\n");
    display(head);

}

void delfromend(){
    struct node*prevnode;
    temp=head;
    while(temp->next!=0){
        prevnode=temp;
        temp=temp->next;
    }
    if(temp==head){
        head=0;
    }
    else{
        prevnode->next=0;
    }
    free(temp);
    printf("list after deleting from end-\n");
    display();

}

void delfrompos(){
    struct node*nextnode;
    int pos,i=1;
    temp=head;
    printf("From which position do you want to delete?\n");
    scanf("%d", &pos);

    if(head==0){
        printf("Empty List!");
    }
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(nextnode);
    printf("\n");
    printf("List after deleting-\n");
    display(head);
}

int main(){
    createlist();
    printf("\n");
    delfrombeg();
    printf("\n");
    delfromend();
    printf("\n");
    delfrompos();

    
    return 0;
}