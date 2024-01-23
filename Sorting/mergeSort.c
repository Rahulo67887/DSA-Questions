#include <stdio.h>
#include<stdlib.h>

int b[100];

void merge(int a[], int lb, int mid, int ub){
    int i=lb, j=mid+1, k=lb;
    while(i<=mid && j<=ub){
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;
        }
        else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else if(j>ub){
        while(i<=mid){
            b[k]=a[i];
            i++;
            k++;
        }
    }
}

void mergeSort(int a[], int lb, int ub){
    if(lb<ub){
        int mid=(lb+ub)/2;
        mergeSort(a, lb, mid);
        mergeSort(a, mid+1, ub);
        merge(a, lb, mid, ub);
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
    mergeSort(arr, lb, ub);
    printf("Array is Sorted!\n Sorted Array-\n");
    for(int i=0; i<n; i++){
        printf("%d\t", b[i]);
    }

    return 0;
}