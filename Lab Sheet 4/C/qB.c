#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void merge(long arr[], long l, long m, long r){
    long i, j, k;
    long n1 = m-l+1;
    long n2 = r-m;
    long L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

long *mergeSort(long arr[], int l, int r)
{
    if (l < r)
    {
        long m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    } else {
        return arr;
    }
}

int main(void){
    long n;
    scanf("%ld", &n);
    long arr[n];
    for(int i=0;i<n;i++){
        long a;
        scanf("%d", &a);
        arr[i] = a;
    }
    long *arr_sorted = mergeSort(arr, 0, n-1);
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", arr[i]);
    // }
    int i;
    bool cond = true;
    for(i = 0;i<n;i++){
        printf("%d %d\n", i, arr[i]);
        if (i > arr[i]) {
            printf("%d", i);
            return 0;
        }
    }
    
    return 0;
}