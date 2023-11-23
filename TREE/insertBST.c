#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*right;
    struct node*left;
};

struct node*create(int data){
    struct node*n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->right=NULL;
    n->left=NULL;
    return n;
}

void insert(struct node*root, int key){
    struct node*prev=NULL;
    struct node*new=create(key);
    while(root!=NULL){
        prev=root;
        if(key<root->data){
            root=root->left;
        }
        else if(key>root->data){
            root=root->right;
        }
        else{
            printf("Cannot insert %d, already in BST", key);
            return;
        }
    }
    
    if(key>prev->data){
        prev->right=new;
    }
    else{
        prev->left=new;
    }
    
}

void preorder(struct node*root){
    if(root==0){
        return;
    }
    else{
        printf("%d\t",root->data);
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
    struct node*p=create(89);
    struct node*p1=create(9);
    struct node*p2=create(8);
    struct node*p3=create(88);
    struct node*p4=create(93);
    struct node*p5=create(79);

    p->left=p1;
    p1->left=p2;
    p1->right=p3;
    p3->left=p5;
    p->right=p4;

    inorder(p);
    printf("\n");
    postorder(p);
    printf("\n");
    preorder(p);
    printf("\n");
   
    insert(p, 616);    
    inorder(p);
    printf("\n");

    return 0;
}