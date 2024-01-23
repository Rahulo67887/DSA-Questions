#include <stdio.h>
#include<stdlib.h>

int a[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
};

struct queue{
    int size;
    int r;
    int f;
    int *arr;
};

int isEmpty(struct queue *q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}

int isFull(struct queue *q){
    if(q->r == q->size-1){
        return 1;
    }
    return 0;
}

void enque( struct queue *q, int val){
    if(isFull(q)){
        printf("Queue is Full!");
    }
    else{
        q->r++;
        q->arr[q->r]=val;
    }
}

int deque(struct queue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("Queue is empty!");
    }
    else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}

int main(){
    struct queue q;
    q.r=0;
    q.f=0;
    q.size=400;
    q.arr=(int *)malloc(q.size*sizeof(int));

    int i=0;
    int node;
    int visited[7]={0,0,0,0,0,0,0};

    printf("%d ", i);
    enque(&q, i);
    visited[i]=1;
    while(!isEmpty(&q)){
        node=deque(&q);
        for(int j=0; j<7; j++){
            if(a[node][j]==1 && visited[j]==0){
                printf("%d ", j);
                enque(&q, j);
                visited[j]=1;
            }
        }
    }

    return 0;
}