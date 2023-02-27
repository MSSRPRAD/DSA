#include<stdio.h>
#include<stdlib.h>

long findGCD(long x, long y){
    if(y==0){
        return x;
    } else {
        return findGCD(y, x%y);
    }
}

//// Find gcd(x,y)
//// x/=prev_Result
//// continue till gcd != 1

long find_result(long x, long y){
    long gcd=-1;
    while(gcd != 1){
        gcd = findGCD(x,y);
        x /= gcd;
    }

    return x;
}



int main(void){
    long a, b;
    scanf("%ld %ld", &a, &b);
    printf("%ld\n", find_result(a,b));
    return 0;
}