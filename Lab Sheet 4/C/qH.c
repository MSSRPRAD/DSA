/*
Minimum Case:
Divide n kings into k-1 rooms (n/k kings in each). Last room has
n-(n/k)*(k-1)
Find combination of this arrangement and add

Maximum Case:
Keep 1 king in (k-1) rooms and all the rest in the last room.
Find the combination for this arrangement.
*/

#include<stdio.h>
#include<stdlib.h>

int main(void){
    long n, k;
    scanf("%ld %ld", &n, &k);
    //// Minimum Case
    long arr[k];
    for(long i=0;i<k-1;i++){
        arr[i] = n/k;
    }
    arr[k-1] = n-(n/k)*(k-1);
    long min;
    for(long i=0;i<k;i++){
        min += arr[i]*(arr[i]-1)/2;
    }
    printf("%ld", min);
    //// Maximum Case
    for(long i=0;i<k;i++){
        arr[i] = 1;
    }
    arr[k-1] = n-k+1;
    long max;
    for(long i=0;i<k;i++){
        max += arr[i]*(arr[i]-1)/2;
    }
    printf(" %ld", max);
    return 0;
}