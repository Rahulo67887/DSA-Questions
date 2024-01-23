#include <stdio.h>
#include<stdlib.h>
int main(){
    int arr[]={23, 43, 54, 74, 65, 74, 2, 78, 33, 50};
    int data,i;
    printf("Enter element you want to search(1 to 100):");
    scanf("%d", &data);

    for(i=0; i<10; i++){
        if(arr[i]==data){
            printf("element is found at index:%d", i);
            break;
        }
    }
    if(i==10){
        printf("Element is not found!");
    }
    
    return 0;
}