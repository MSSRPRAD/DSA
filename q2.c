#include <stdio.h>
int main()
{
    //Take in input of array1
    int m, n;
    int counter = 0;
    scanf("%d %d", &m, &n);
    int A[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    //Take in input of array 2
    int p, q;
    scanf("%d %d", &p, &q);
    int B[p][q];
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }
    //Iterate along elements of array1
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //If first element of B matches, start checking for subarray match
            if (A[i][j] == B[0][0])
            {
                
                for (int a = i; a < (p + i); a++)
                {
                    for (int b = j; b < (q + j); b++)
                    {

                        if (A[a][b] == B[a - i][b - j])
                        {
                            counter++;
                        }
                    }
                }
            }
        }
    }
    //If proper match found then print YES
    if (counter == p * q)
    {
        printf("YES");
    }
    //Otherwise check for partial match
    else
    {
        //Iterate along elements of array1 again
        //This time checking if removing some columns of array2 results in total match
        int colcounter = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < p; k++)
                {   
                    //Start checking if a row of B is contained in A
                    if (A[i][j] == B[k][0])
                    {
                        for (int b = j; b < (p + j); b++)
                        {
                            if (A[i][b] == B[k][b - j])
                            {
                                colcounter++;
                            }
                        }
                    }
                }
            }
        }
        if (colcounter == q)
        {
            printf("partial");
        }
        else
        {
            int rowcounter = 0;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < p; k++)
                    {
                        if (A[i][j] == B[0][k])
                        {
                            for (int a = i; a < (p + i); a++)
                            {
                                if (A[a][j] == B[a - i][k])
                                {
                                    rowcounter++;
                                }
                            }
                        }
                    }
                }
            }
            if (rowcounter == p)
            {
                printf("partial");
            }
            else
            {
                printf("no");
            }
        }
    }
}