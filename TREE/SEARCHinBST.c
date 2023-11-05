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

struct node* search(struct node*root, int key){
    if(isBST(root)){
        if(root==0){
            return 0;
        }
        else if(key==root->data){
            return root;
        }
        else if(key<root->data){
            return search(root->left, key);
        }
        else if(key>root->data){
            return search(root->right, key);
        }
    }
    else{
        printf("Error, given tree is not a BST");
    }
}

int main(){
    struct node*root;
    root=create();

    int k;
    printf("What do you want to search?\n");
    scanf("%d", &k);


    struct node*s=search(root, k);
    if(s!=0){
        printf("FOUND:%d",s->data);
    }
    else{
        printf("Element is not found!");
    }
    return 0;
}