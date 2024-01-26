#include <stdio.h>
#include<stdlib.h>

void countSort(int a[], int n){
    int key=a[0];
    for(int i=0; i<n; i++){
        if(a[i]>key){
            key=a[i];
        }
    }
    int count[key+1];
    int b[n];
    for(int i=0; i<=key; i++){
        count[i]=0;
    }
    for(int i=0; i<n; i++){
        count[a[i]]++;
    }
    for(int i=1; i<=key; i++){
        count[i]=count[i-1]+count[i];
    }
    for(int i=n-1; i>=0; i--){
        b[--count[a[i]]]=a[i];
    }
    for(int i=0; i<n; i++){
        a[i]=b[i];
    }
}

int main(){
    int n;
    printf("How many elements do you want in the array?");
    scanf("%d", &n);
    int *arr=(int *)malloc(n*sizeof(int));
    printf("Enter %d elements of array:",n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    countSort(arr,4);

    printf("Array is Sorted!\n Sorted Array-\n");
    for(int i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
    
    return 0;
}