#include <stdio.h>
#include<stdlib.h>
int main(){
    int n=10;
    int arr[]={1, 23, 45, 65, 78, 87, 88, 90, 95, 99};
    int data;
    printf("Enter element you want to search(1 to 100):");
    scanf("%d", &data);

    int mid, l=0, r=n-1, found=0;
    while(l<r){
        mid=(l+r)/2;
        if(data==arr[mid]){
            printf("Element found at index: %d", mid);
            found=1;
            break;
        }
        else if(data<arr[mid]){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    if(!found){
        printf("Element not found!");
    }
    return 0;
}