// #include<stdlib.h>
// #include<stdio.h>

// int main(void){
//     long a;
//     scanf("%ld", &a);
//     long arr[a];
//     for(long i=0;i<a;i++){
//         scanf("%ld", &arr[i]);
//     }
//     // for(long i=0;i<a;i++){
//     //     printf("%ld ", arr[i]);
//     // }
//     long freq[10];
//     for(long i=0;i<10;i++){
//         freq[i] = 0;
//     }
//     for(long i=0;i<a;i++){
//         freq[arr[i]%10] += 1;
//     }
//     printf("\n\n");
//     for(long i=0;i<10;i++){
//         printf("%ld ", freq[i]);
//     }
//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>
void countSort(int arr[],int n,int exp){
    int *c=malloc(10*sizeof(int));
    for(int i=0;i<10;i++){
        c[i]=0;
    }
    for(int i=0;i<n;i++){
        c[(arr[i]/exp)%10]++;
    }
    for(int i=1;i<10;i++){
        c[i]=c[i]+c[i-1];
    }
    int *sorted=malloc(n*sizeof(int));
    for(int j=n-1;j>=0;j--){
        sorted[c[(arr[j]/exp)%10]-1]=arr[j];
        c[(arr[j]/exp)%10]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=sorted[i];
    }
}
void radixSort(int arr[],int n){
    int max=-999;
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    for(int exp=1;(max/exp)>0;exp*=10){
       countSort(arr,n,exp);
       for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
       }
       printf("\n");
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int *arr=malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    radixSort(arr,n);
    return 0;
}