#include<stdlib.h>
#include<stdio.h>

int noOfPlanksSatisfies(int *arr, int n, int k, int mid){
    int count = 0;
    for(int i=0;i<n;i++){
        count+=arr[i]/mid;
    }
    if(count>=k){
        return 1;
    } else {
        return 0;
    }
}

int solve(int *arr, int n, int k, int max){
    int left = 1;
    int right = max;
    int mid;
    while(left<=right){
        mid = (left+right)/2;
        if(noOfPlanksSatisfies(arr, n, k, mid)){
            left += 1;
        } else {
            right -= 1;
        }
    }
    return mid-1;
}


int main(void){
    int n,k;
    scanf("%d %d", &n, &k);
    int arr[n];
    int max=0;
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
        if(max<arr[i]){
            max=arr[i];
        }
    }

    printf("%d", solve(arr, n, k, max));
    return 0;
}