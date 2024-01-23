#include <stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("How many elements do you want in the array?");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements of array:",n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<n-1; i++){
        int swap=0;
        for(int j=0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swap=1;
            }
        }
        if(swap==0){
            break;
        }
    }

    printf("Array is Sorted!\n Sorted Array-\n");
    for(int i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }

    return 0;
}