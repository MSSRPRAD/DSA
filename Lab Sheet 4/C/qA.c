#include<stdio.h>
#include<stdlib.h>

void merge(long arr[], long l, long m, long r){
    long i, j, k;
    //// No of elements in left array
    long n1 = m-l+1;
    //// No of elements in right array
    long n2 = r-m;

    //To store the left and right arrays
    long L[n1], R[n2];

    //Copying the contents of left and right halves in the respective left and right arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    // For the left one, indexing
    i = 0;
    // For the right one, indexing
    j = 0;
    // To fill the new merged array
    // Indexing started from l
    k = l;

    //While elements are there in left and right arrays
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

    // If no elements in right but elements in left
    // Fill the remaining with these elements
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    // If no elements in left but elements in right
    // Fill the remaining with these elements
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

struct Slot_t {
    int start;
    int end;
};

typedef struct Slot_t Slot;

int main(void){
    int no;
    scanf("%d", &no);
    Slot arr[no];
    for(int i=0;i<no;i++){
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    int pointer = 0;
    

    return 0;
}