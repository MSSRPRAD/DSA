#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int gcd(int a, int b){
    if(b==0){
        return a;
    } else {
        return gcd(b,a%b);
    }
}

int findGCD(int j, int *arr, int len){
    int result = arr[0];
    for (int i=0;i<len;i++){
        if(i==j){
            
        } else {
            result = gcd(result,arr[i]);
        }
    }
    return result;
}

int main(void){
    int a;
    scanf("%d", &a);
    int arr[a];
    for (int i=0;i<a;i++){
        scanf("%d", &arr[i]);
    }
    int greatest = 0;
    for(int i=0;i<a;i++){
        if(findGCD(i, arr, a)>greatest){
            greatest = findGCD(i, arr, a);
        }
    }
    printf("\n%d\n", greatest);
}