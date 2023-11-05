#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *right, *left;
};

struct node* create(){
    int x;
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    printf("Enter data(-1 for no node):");
    scanf("%d", &x);
    if(x==-1){
        return 0;
    }
    else{
        newnode->data=x;
        printf("Enter left child of %d\n", x);
        newnode->left=create();
        printf("Enter right child of %d\n", x);
        newnode->right=create();
        return newnode;
    }
}

int isBST(struct node*root){
    static struct node *prev=0;
    if(root!=0){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=0 && root->data <= prev->data){
            return 0;
        }
        prev =root;
        return isBST(root->right);
    }
    return 1;
}

int main(){
    struct node*root;
    root=create();

    if(isBST(root)){
        printf("Given tree is a BST.");
    }
    else{
        printf("NOT a BST.");
    }

    return 0;
}