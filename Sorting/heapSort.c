#include <stdio.h>
#include<stdlib.h>

void maxHeapify(int a[], int n, int i){
    int largest=i;
    int l=(2*i);
    int r=(2*i)+1;
    while(l<=n && a[l]>a[largest]){
        largest=l;
    }
    while(r<=n && a[r]>a[largest]){
        largest=r;
    }
    if(largest!=i){
        int temp=a[largest];
        a[largest]=a[i];
        a[i]=temp;
        maxHeapify(a, n, largest);
    }
}

void heapSort(int a[], int n){
    for(int i=n/2; i>=1; i--){
        maxHeapify(a, n, i);
    }
    for(int i=n; i>=1; i--){
        int temp=a[i];
        a[i]=a[1];
        a[1]=temp;
        maxHeapify(a, n, 1);
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

    heapSort(arr, n);

    printf("Array is Sorted!\n Sorted Array-\n");
    for(int i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
    return 0;
}