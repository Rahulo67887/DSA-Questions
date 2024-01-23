#include <stdio.h>
#include<stdlib.h>

int partition(int a[], int lb, int ub){
    int pivot=a[lb];
    int start=lb;
    int end=ub;
    while(start<end){
        while(a[start]<=pivot){
            start++;
        }
        while(a[end]>pivot){
            end--;
        }
        if(start<end){
            int temp=a[start];
            a[start]=a[end];
            a[end]=temp;
        }
    }
    int temp=a[lb];
    a[lb]=a[end];
    a[end]=temp;
    return end;
}

void quickSort(int a[], int lb, int ub){
    if(lb<ub){
        int loc=partition(a, lb, ub);
        quickSort(a, lb, loc-1);
        quickSort(a, loc+1, ub);
    }
}

int main(){
    int n;
    printf("How many elements do you want in the array?");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements of array:",n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int lb=0, ub=n-1;
    quickSort(arr, lb, ub);

    printf("Array is Sorted!\n Sorted Array-\n");
    for(int i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
    
    return 0;
}