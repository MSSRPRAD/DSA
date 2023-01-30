#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int max;
int r, c;
int numb;

int findNoOfDigits(int n){
    int no;
    while(n>0){
        n/=10;
        no++;
    }
    return no;
}

void print(int *arr, int max){
    for(int k=0;k<max;k++){
        for(int l=0;l<max;l++){
            //int x = findNoOfDigits(*((arr+k*max)+l));
            printf("%-4d",*((arr+k*max)+l));
            if(l!=max-1) printf("---");
            if(l==max-1) printf("|");
        }
        if(k!=max-1)printf("\n|\t\t\t    |\n" );
    }
}

int fillLeft(int *arr, int max, int row, int column, int number){
    int pos;
    for(int k=column;k>-1;k--){
        if(*((arr+row*max)+k)==0){ 
            *((arr+row*max)+k) = number;
            printf("%d ", *((arr+row*max)+k));
            pos=k;
            number-=2;
        }
    }
    numb = number+2;
    return pos;
}

int fillRight(int *arr, int max, int row, int column, int number){
    int pos;
    for(int k=column;k<max;k++){
        if(*((arr+row*max)+k)==0){ 
            *((arr+row*max)+k) = number;
            printf("%d ", *((arr+row*max)+k));
            pos=k;
            number-=2;
        }
    }
    numb = number-2;
    return pos;
}

int fillTop(int *arr, int max, int row, int column, int number){
    int pos;
    for(int k=row;k>-1;k--){
        if(*((arr+k*max)+column)==0){
            *((arr+k*max)+column)=number;
            printf("%d ", *((arr+k*max)+column));
            pos=k;
            number-=2;
        }
    }
    numb=number+2;
    return pos;
}

int fillDown(int *arr, int max, int row, int column, int number){
    int pos;
    for(int k=row;k<max;k++){
        if(*((arr+k*max)+column)==0){
            *((arr+k*max)+column)=number;
            printf("%d ", *((arr+k*max)+column));
            pos=k;
            number-=2;
        }
    }
    numb=number+2;
    return pos;
}


int main(void){

    int n;
    scanf("%d",&n);

    int arr[n][n];
    for(int k=0;k<n;k++){
        for(int l=0;l<n;l++){
            arr[k][l]=0;
        }
    }

    //print(&arr[0][0],n);

    //Initially
    c = n;
    r=n;
    numb=2+(n*n-2)*2+4;

    
    int rw = n-1,cl=n;
    for(int g=0;g<n;g++){ 
        cl = fillLeft(&arr[0][0], n, rw, cl-1, numb-2);
        printf("\n\n%d\t%d\n\n", cl, numb);
        rw = fillTop(&arr[0][0], n, rw,cl,numb-2);
        printf("\n\n%d\t%d\n\n", rw, numb);
        cl = fillRight(&arr[0][0], n, rw, cl, numb-2);
        printf("\n\n%d\t%d\n\n", cl, numb-2);
        rw=fillDown(&arr[0][0], n, rw, cl, numb+2);
        printf("\n\n%d\t%d\n\n", rw, numb);
    }

    printf("\n\n");
    print(&arr[0][0],n);

}