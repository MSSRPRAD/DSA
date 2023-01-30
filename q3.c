#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>



void print(int *matrix, int max){
    for(int k=0;k<max;k++){
        printf("%d ", matrix[k]);
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


void swap(int *matrix, int x, int y){
    int temp = matrix[x];
    matrix[x]=matrix[y];
    matrix[y]=temp;
    return;
}

int pos;
bool checkIfSumPossible(int *matrix1, int sum, int max){
    pos=-1;
    int s=0;
    for(int k=0;k<max;k++){
        s+=matrix1[k];
        if(s==sum){ 
            pos=k;
            return true;
        }
    }
    return false;
}

int p=0;
bool condition=false;
void permute(int* a, int *ind, int l, int r, int n, int sum)
{
    int i;
    if (l == r && !condition){
        p++;
        //printf("\nCurrent Permutation (%d):\n",p);
        //print(a, n);
        //printf("\n");
        //print(ind, n);
        condition = checkIfSumPossible(a, sum, n);
        if(condition){ 
            printf("POSSIBLE\nPosition is: %d\n", pos);
            for(int g=0;g<=pos;g++){
                printf("%d ", ind[g]);
            }
        }

    }
    else{
        for (i = l; i <= r; i++) {
            swap(a, l, i);
            swap(ind, l,i);
            permute(a, ind, l + 1, r, n, sum);
            swap(a,l,i);
            swap(ind, l,i);
        }
    }
}


int main(void){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int k=0;k<n;k++){
        scanf("%d", &arr[k]);
    }
    int subSum;
    scanf("%d", &subSum);

    // printf("\n%d\n\n", subSum);
    // print(arr, n);
    // printf("\n\n");

    int index[n];
    for(int k=0;k<n;k++){
        index[k]=k;
    }

    // printf("\n");
    // print(index, n);
    // printf("\n");

    permute(arr, index,0,n-1,n, subSum);

    if(!condition){
        printf("NOT POSSIBLE");
    }

    

    return 0;
}