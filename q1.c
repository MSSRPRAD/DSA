#include<stdio.h>
#include<stdlib.h>

int main(void){

    int m, n;

    printf("Enter m:\t"); scanf("%d", &m);
    printf("\nEnter m:\t"); scanf("%d", &n);

    printf("\n\nEnter the values of the Array:\n\n");

    printf("Enter ri, ci, rh, ch:\t"); int ri,ci,rh,ch; scanf("%d %d %d %d", &ri,&ci,&rh,&ch);

    printf("\n");

    //Making Dynamically allocated arrays

    int** A = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
        A[i] = (int*)malloc(n * sizeof(int));

    int** B = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
        B[i] = (int*)malloc(n * sizeof(int));

    //Taking input into A
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++){
            printf("Row %d , Column %d :\t", i,j);
            scanf("%d", &A[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    //Printing the array A
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d\t", A[i][j]);
        printf("\n");
    }

    //Initializing B
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++){
            B[i][j]=0;
        }
        printf("\n");
    }

    //Printing the array B
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d\t", B[i][j]);
        printf("\n");
    }

    printf("\n\n");

    //Initializing B
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++){
            if(i==0 && j==0){
                B[i][j]=A[i][j];
            } else{
                for(int k=0;k<=i-1;k++){
                    for(int l=0;l<n;l++){
                        B[i][j]+=A[k][l];
                    }
                }

                for(int k=0;k<=j;k++){
                    B[i][j]+=A[i][k];
                }
            }
        }
    }

    //Printing the array B
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d\t", B[i][j]);
        printf("\n");
    }

    printf("\n\n%d  %d  %d  %d\n\n", ri,ci,rh,ch);

    if(ri+rh<=m && ci+ch<=n){
        int sum=0;
        for(int k=ri;k<ri+rh;k++){
            for(int l=ci;l<ci+ch;l++){
                sum+=B[k][l];
            }
        }
        printf("SUM IS:\t%d\n\n", sum);
    } else{
        printf("NOT POSSIBLE");
    }

 
    for (int i = 0; i < m; i++){
        free(A[i]);
        free(B[i]);
    }
 
    free(A); free(B);

    return 0;
}