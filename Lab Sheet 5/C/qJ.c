#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void printArray(int *arr, int n){
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectKItems(int *arr, int n, int k){
    int i;
    //// Reservoir is deep copy of arr
    int reservoir = arr[0];
    //// seed the srand
    srand(time(NULL));
    //// Iterate from the (k+1)th element 
    //// to the nth element
    for(i = 1; i<n;i++){
        //// Pick a random index from 0 to i
        int j = rand()%(i+1);
        //// If the randomly picked index is smaller than k then,
        //// replace the element present at that index with
        //// new element from the stream
        if(j<1){
            reservoir = arr[i];
        }
    }

    printf("%d\n", reservoir);
}

int main(void){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    for(int i=1;i<=n;i++){
        selectKItems(arr,i,1);
    }
    return 0;
}