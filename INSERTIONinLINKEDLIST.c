#include <stdio.h>
#include<stdlib.h>

struct node{
        int data;
        struct node*next;
    };
struct node*head, *newnode, *temp;

void display(struct node *head){
    printf("\n");
    temp=head;
    while(temp!=0){
        printf("%d\n", temp->data);
        temp=temp->next;
    }
}

void insertingATbeginning(struct node**head){
    printf("\n");

    newnode=(struct node*)malloc(sizeof(struct node));
    printf("What do you want to insert at the beginning?\n");
    scanf("%d", &newnode->data);
    newnode->next=*head;
    *head=newnode;

    printf("\n");
    printf("LIST AFTER INSERTING AT THE BEGINNING-");
    display(*head);
}

void insertingATend(struct node**head){
    printf("\n");

    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    printf("What do you want to insert at the end?\n");
    scanf("%d", &newnode->data);
    newnode->next=0;

    temp=*head;
    while(temp->next!=0){
        temp=temp->next;
    }
    temp->next=newnode;

    printf("\n");
    printf("LIST AFTER INSERTING AT THE END-");
    display(*head);
}

int insertingAFTERposition(struct node **head){
    int pos,i=1,count=0;

    temp=*head;
    while(temp!=0){
        temp=temp->next;
        count++;
    }

    printf("\n");
    printf("After which position do you want to insert data?\n");
    scanf("%d", &pos);
    if(pos>count){
        printf("INVALID POSITION!");
        return 0;
    }
    else{
        newnode=(struct node*)malloc(sizeof(struct node));
        temp=*head;
        while(i<pos){
            temp=temp->next;
            i++;
        }
        printf("what do you want to insert?\n");
        scanf("%d", &newnode->data);
        newnode->next=temp->next;
        temp->next=newnode;
    }

    printf("\n");
    printf("List AFTER INSERTING DATA-");
    display(*head);
    return 0;
}

int main(){
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

        printf("Do you want to continue?(press '1' for 'yes' and '0' for 'no'):");
        scanf("%d", &choice);
    }

    printf("\n");
    printf("YOUR LIST:");
    display(head);
insertingAFTERposition(&head);
    insertingATbeginning(&head);//INSERTING AT THE BEGINNING
    insertingATend(&head);//INSERTING AT THE END
    
    return 0;
}