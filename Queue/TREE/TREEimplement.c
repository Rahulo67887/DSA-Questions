#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *right, *left;
};

struct node* create(){
    int x;
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    printf("Enter data(-1 for no node:)");
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

void preorder(struct node*root){
    if(root==0){
        return;
    }
    else{
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node*root){
    if(root==0){
        return;
    }
    else{
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

void inorder(struct node*root){
    if(root==0){
        return;
    }
    else{
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

int main(){
    struct node*root;
    root=create();

    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    return 0;
}