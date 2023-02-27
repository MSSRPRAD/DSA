#include<stdio.h>
#include<stdlib.h>

long countZero(long no){
    long count = 0;
    while(no>0){
        count += no/5;
        no/=5;
    }
    return count;
}

long freq[100000000];

long count_pairs(long *arr, long size){
    for(long i=0;i<size;i++){
        long tmp = countZero(arr[i]);
        freq[tmp]+=1;

    }
    long total_count = 0;
    for(long i=0;i<100000000;i++){
        //// J nos have same no of zeros
        long j = freq[i];
        //// jC2 pairs are possible
        total_count += j*(j-1)/2;
    }

    return total_count;
}


int main(void){

    for(long i=0;i<100000000;i++){
        freq[i]=0;
    }

    long no;
    scanf("%ld", &no);
    long arr[no];
    for(long i=0;i<no;i++){
        scanf("%ld", &arr[i]);
    }
    
    printf("%ld", count_pairs(arr, no));
    

    return 0;
}