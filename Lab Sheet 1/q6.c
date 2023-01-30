#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int freqArr[10];


bool isPrime(int num){
    for(int i=2;i*i<=num;i++){
        //If some number smaller than num is dividing num
        if(num%i==0){ return false;}
    }
    return true;
}

void updateFreqArray(int *matrix, int num){
    while(num>0){ 
        int d;
        d = num%10;
        matrix[d]++;
        num/=10;
    }
}

void printArray(int *matrix, int max){
    for(int k=0;k<max; k++){
        printf("%d ", matrix[k]);
    }
}

int findMax(int *matrix, int max){
    int maximum=0;
    int posMax;
    for(int k=0;k<max;k++){
        if(matrix[k]>=maximum) {
            posMax = k;
            maximum = matrix[k];
        }
    }
    return posMax;
}

int main(void){

    
    for(int k=0;k<10;k++){
        freqArr[k]=0;
    }

    int a,b;

    scanf("%d %d", &a, &b);
    //printf("\nA is:\t%d\t\tB is:\t%d\n\n", a, b);

    for(int k=a;k<=b;k++){
        //printf("%d : %d\n", k, isPrime(k));
        if(isPrime(k) && k!=1){ 

            //printf("%d\n", k); 

            updateFreqArray(freqArr, k);

            //printArray(freqArr, 10);
            //printf("\n");
            
        }
    }

    int posMax = findMax(freqArr, 10);

    printf("%d %d", posMax, freqArr[posMax]);




    return 0;
}