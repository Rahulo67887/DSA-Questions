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

struct node*inorderpredecessor(struct node*root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}

struct node* deletenode(struct node*root, int value){
    struct node*ipre;
    if(root==NULL){
        return NULL;
    }
    else if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    if(value>root->data){
        root->right=deletenode(root->right, value);
    }
    else if(value<root->data){
        root->left=deletenode(root->left, value);
    }
    else{
        ipre=inorderpredecessor(root);
        root->data=ipre->data;
        root->left=deletenode(root->left, ipre->data);
    }
    return root;
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
   
    deletenode(p, 93);
    inorder(p);
    printf("\n");
   
   switch (expression)
   {
   case /* constant-expression */:
    /* code */
    break;
   
   default:
    break;
   }

    return 0;
}