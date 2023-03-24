#include <iostream>
#include <stack>

int *prev_greater_element(int *arr, int *result, int n)
{
    std::stack<int> stack;
    for (int i = 0; i < n; i++)
    {
        while (!stack.empty() && stack.top() <= arr[i])
        {
            stack.top() = arr[i];
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
        stack.push(arr[i]);
    }

    return result;
}

int *next_greater_element(int *arr, int *result, int n)
{
    std::stack<int> stack;
    for (int i = n - 1; i > -1; i--)
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

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    int *bigger_array = new int[2 * n];
    for (int i = 0; i < n; i++)
    {
        bigger_array[i] = arr[i];
        bigger_array[n + i] = arr[i];
    }
    int *result = new int[2 * n];
    result = next_greater_element(bigger_array, result, 2 * n);
    for (int i = 0; i < n; i++)
    {
        if (result[i] != -1)
            result[i] = result[i] - i;
        std::cout << result[i] << " ";
    }

    return 0;
}