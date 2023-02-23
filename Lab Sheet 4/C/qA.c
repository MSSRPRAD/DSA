#include<stdio.h>
#include<stdlib.h>

int main(void){
    long n;
    scanf("%ld", &n);
    long arr[n][2];
    for(int i=0;i<n;i++){
        long a,b;
        scanf("%d %d", &a, &b);
        arr[i][0] = a;
        arr[i][1] = b;
    }
    long sorted[n][2];
    // for(int i=0;i<n;i++){
    //     long a,b;
    //     a=arr[i][0];
    //     b=arr[i][1];
    // }
    return 0;
}