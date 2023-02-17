#include<stdio.h>
#include<stdlib.h>

int findHalfwayStep(long int sz, long int long target){
    long int left = 1;
    long int right = sz;
    long int i;
    while(left < right){
        i  = (left+right)/2;
        int long sum = sz*(sz-1)/2-i*(i+1)/2+i;
        if(sum == target){
            break;
        } else if(sum<target){
            right-=1;
        } else{
            left+=1;
        }
        //printf("\n%ld %d %d %d\n", sum, sz-i+1, left, right);
    }
    return sz-i;
}

int main(void){
    long int size;
    scanf("%ld", &size);
    //printf("%ld", size);
    //Make halfway = [size*(size-1)/4]
    long int halfway = ((size*(size-1))/2); 
    halfway = halfway/2;
    printf("\n%d\n", halfway);
    printf("%d", findHalfwayStep(size, halfway));
    return 0;
}