#include <iostream>
#include <deque>

int main(void)
{
    int n, k;
    std::cin >> n;
    std::cin >> k;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::deque<int> D;
    int i, j;
    while (j < n)
    {
        if (D.empty())
        {
            D.push_back(arr[j]);
        }
        else
        {
            while (!D.empty() && arr[j] > D.back())
            {
                D.pop_back();
            }
            D.push_back(arr[j]);
        }

        if ((j - i + 1) == k)
        {
            std::cout << D.front() << " ";
            if (arr[i] == D.front())
            {
                D.pop_front();
            }
            i += 1;
        }

        j += 1;
    }
    return 0;
}