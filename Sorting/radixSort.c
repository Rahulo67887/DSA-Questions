#include <stdio.h>
#include<stdlib.h>

void countSort(int a[], int n, int pos){
    int count[10]={0};
    int b[n];
    for(int i=0; i<n; i++){
        count[(a[i]/pos)%10]++;
    }
    for(int i=1; i<10; i++){
        count[i]=count[i-1]+count[i];
    }
    for(int i=n-1; i>=0; i--){
        b[--count[(a[i]/pos)%10]]=a[i];
    }
    for(int i=0; i<n; i++){
        a[i]=b[i];
    }
}

void radixSort(int a[], int n){
    int max=a[0];
    for(int i=0; i<n; i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    for(int pos=1;max/pos>0; pos*=10){
        countSort(a, n, pos);
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

    radixSort(arr, n);

    printf("Array is Sorted!\n Sorted Array-\n");
    for(int i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }

    free(arr);

    return 0;
}