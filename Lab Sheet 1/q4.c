#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>


void print(int *matrix, int max){
    for(int k=0;k<max;k++){
        if(matrix[k]!=0) printf("%d ", matrix[k]);
    }
    return;
}

int findK(int *matrix, int max, int k){
    for(int g=0;g<max;g++){
        if(matrix[g]==k){
            return g;
        }
    }
}

int findlastGreaterThanK(int *matrix, int max, int k){
    int pos;
    for(int g=0;g<findK(matrix, max, k);g++){
        if(matrix[g]>k){
            pos=g;
        }
    }
    return pos;
}

int findFirstLesserThanK(int *matrix, int max, int k){
    int pos;
    for(int g=findK(matrix, max, k)+1;g<max;g++){
        if(matrix[g]<k){
            pos=g;
            return pos;
        }
    }
}


void swap(int *matrix, int x, int y){
    int temp = matrix[x];
    matrix[x]=matrix[y];
    matrix[y]=temp;
    return;
}

bool sorted(int *matrix, int max, int k){
   for(int g=0;g<max;g++){
        if(matrix[g]>k && g<findK(matrix, max, k))
            return false;
        if(matrix[g]<k && g>findK(matrix, max, k))
            return false;
   }
   return true;
}

void sortSpecial(int *matrix, int max, int k){
    print(matrix, max);
    while(!sorted(matrix, max, k)){
        for(int g=0;g<max;g++){
            if(matrix[g]>k && g<findK(matrix, max, k)){
                printf("\nSwapping %d and %d\n",matrix[findlastGreaterThanK(matrix, max, k)], matrix[findK(matrix, max, k)] );
                swap(matrix, findlastGreaterThanK(matrix, max, k), findK(matrix, max, k));
                print(matrix, max);
            }
            if(matrix[g]<k && g>findK(matrix, max, k)){
                swap(matrix, findFirstLesserThanK(matrix, max, k), findK(matrix, max, k));
                printf("\nSwapping %d and %d\n",matrix[findFirstLesserThanK(matrix, max, k)], matrix[findK(matrix, max, k)]);
                print(matrix, max);            
            }
        }
        

    }
    
    return;
}

int main(void){
    int n;
    scanf("%d", &n);
    int arr[n+1];
    for(int k=0;k<n;k++){
        scanf(" %d", &arr[k]);
    }
    arr[n]=0;
    printf("\n");
    print(arr, n+1);
    printf("\nk:\t%d\nn:\t%d\n\n", 0, n+1);

    sortSpecial(arr, n+1, 0);
    
    printf("\n\n");
    print(arr, n+1);
    
    

    return 0;
}