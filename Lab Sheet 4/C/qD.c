#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void){
    long n;
    int q;
    scanf("%ld %d", &n, &q);
    long arr[q];
    for (int i = 0; i < q; i++)
    {
        long tmp;
        scanf("%ld", &tmp);
        arr[i]=tmp;
    }
    for (int i = 0; i < q; i++)
    {
        printf("%ld ", arr[i]);
    }

    long count[q];

    for(int i=0;i<q;i++){

        count[i]=0;

        long no = arr[i];
        bool prime[no+1];
        for(long k=0;k<no+1;k++){
            prime[k] = true;
        }
        prime[0] = false;
        prime[1] = false;

        if(no<=2){
            break;
        }

        for (long k = 2; k < no+1; k++) {
            if (prime[k]) {

                for (long j = 2*k; j < no+1; j+=k) {

                    prime[j] = false;

                }

            }
        }

        for(long j=0;j<no+1;j++){
            if(prime[j]){
                count[i]++;
            }
        }


    }
    printf("\n\n");
    for(int i=0;i<q;i++){
        printf("%ld ", count[i]);
    }

    return 0;
}