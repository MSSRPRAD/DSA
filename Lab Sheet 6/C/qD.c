#include <stdio.h>

int main()
{
    //// Input

    int n;
    scanf("%d", &n);
    int arr[n];
    int count[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        count[i] = 0;
    }

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        count[arr[i]] += 1;
        while (j <= i && count[arr[j]] != 1)
        {
            j++;
        }
        if (j > i)
        {
            printf("-1 ");
        }
        else
        {
            printf("%d ", arr[j]);
        }

        printf("\ni: %d, j: %d\n", i, j);
    }

    return 0;
}