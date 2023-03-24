#include <iostream>
#include <stack>

int *prev_greater_element(int *arr, int *result, int n)
{
    std::stack<int> stack;
    for (int i = 0; i < n; i++)
    {
        while (!stack.empty() && arr[stack.top()] <= arr[i])
        {
            stack.pop();
        }
        if (stack.empty())
        {
            result[i] = -1;
        }
        else
        {
            result[i] = stack.top();
        }
        stack.push(i);
    }

    return result;
}

int main(void)
{
    int n;
    std::cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    std::stack<int> stock;
    int *spread = new int[n];
    int left = 0;

    spread = prev_greater_element(arr, spread, n);

    std::cout << std::endl;
    for (int i = 0; i < n; i++)
    {
        spread[i] = i - spread[i];
        std::cout << spread[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}