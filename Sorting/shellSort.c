#include <stdio.h>
#include<stdlib.h>

void shellSort(int a[], int n){
    for(int gap=n/2; gap>=1; gap/=2){
        for(int j=gap; j<n; j++){
            for(int i=j-gap; i>=0; i-=gap){
                if(a[i+gap]>a[i]){
                    break;
                }
                else{
                    int temp=a[i+gap];
                    a[i+gap]=a[i];
                    a[i]=temp;
                }
            }
        }
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

    shellSort(arr, n);

    printf("Array is Sorted!\n Sorted Array-\n");
    for(int i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }

    free(arr);
    return 0;
}