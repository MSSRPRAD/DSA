#include<stdio.h>
#include<stdlib.h>

int findHalfwayStep(int sz, int long target){
    int left = 1;
    int right = sz;
    int i;
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
    long int halfway = ((size*(size-1))/2); 
    halfway -= halfway/2;
    printf("%d", findHalfwayStep(size, halfway));
    return 0;
}