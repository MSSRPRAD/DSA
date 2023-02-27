#include<stdio.h>
#include<stdlib.h>

int main(void){
    int no;
    int cand;
    scanf("%d %d", &no, &cand);
    int arr[no];
    int freq[no];
    for(int i=0;i<no;i++){
        scanf("%d", &arr[i]);
        freq[i] = 0;
    }
    int index[no];
    for(int i=0;i<no;i++){
        freq[arr[i]-1]+=1;
        index[i]=i+1;
    }
    
    // for(int i=0;i<no;i++){
    //     printf("%d ", freq[i]);
    // }
    // printf("\n\n");

    // for(int i=0;i<no;i++){
    //     printf("%d ", index[i]);
    // }

    printf("\n\n");
    for(int i=0;i<no-1;i++){
        for(int j=0;j<no-i-1;j++){
            if(freq[j+1]>freq[j]){
                int tmp = freq[j+1];
                freq[j+1] = freq[j];
                freq[j] = tmp;

                int tmp1 = index[j+1];
                index[j+1] = index[j];
                index[j] = tmp1;
            }
        }
    }
    printf("\n\n");
    for(int i=0;i<cand;i++){
        printf("%d ", index[i]);
    }
    return 0;
}