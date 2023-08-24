#include<stdio.h>
#include<stdlib.h>
int main(){
    int a[50], size, num, pos;

    printf("Enter size of array(should not exceed than 50):\n");
    scanf("%d", &size);

    printf("Enter elements of array:\n");
    for(int i=0; i<size; i++){
        scanf("%d", &a[i]);
    }

    printf("\n");

    printf("Elements in array:\n");
    for(int i=0; i<size; i++){
        printf("%d\n", a[i]);
    }

    printf("\n");

    printf("Enter the number you want to insert:");
    scanf("%d", &num);
    printf("Enter the position at which you want to insert:");
    scanf("%d", &pos);

    if(pos<=0 || pos>size+1){
        printf("Invalid position!");
        return 0;
    }
    else{
        for(int i=size-1; i>=pos-1; i--){
            a[i+1]=a[i];
        }
    }

    a[pos-1]=num;
    size++;

    printf("\n");

    printf("array after inserting:\n");
    for(int i=0; i<size; i++){
        printf("%d\n", a[i]);
    }

    printf("\n");

    printf("from which element do you want to delete:");
    scanf("%d", &pos);

    if(pos<=0 || pos>size+1){
        printf("Invalid position!");
        return 0;
    }
    else{
        for(int i=pos-1; i<size-1; i++){
        a[i]=a[i+1];
        }
    }

    size--;

    printf("\n");

    printf("array after deleting element:\n");
    for(int i=0; i<size; i++){
        printf("%d\n", a[i]);
    }
    return 0;
}