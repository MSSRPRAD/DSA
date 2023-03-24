#include <iostream>
#include <stack>

int *prev_smaller_element(int *arr, int *result, int n)
{
    std::stack<int> stack;
    for (int i = 0; i < n; i++)
    {
        while (!stack.empty() && arr[stack.top()] >= arr[i])
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

int *next_smaller_element(int *arr, int *result, int n)
{
    std::stack<int> stack;
    for (int i = n - 1; i > -1; i--)
    {
        while (!stack.empty() && arr[stack.top()] >= arr[i])
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
    // READ THE INPUT
    int no;
    std::cin >> no;
    int *input = new int[no];
    for (int i = 0; i < no; i++)
    {
        std::cin >> input[i];
    }
    int *prev = new int[no];
    prev = prev_smaller_element(input, prev, no);
    // for (int i = 0; i < no; i++)
    // {
    //     std::cout << prev[i] << " ";
    // }
    // std::cout << "\n";
    int *nxt = new int[no];
    nxt = next_smaller_element(input, nxt, no);
    // for (int i = 0; i < no; i++)
    // {
    //     std::cout << nxt[i] << " ";
    // }
    // std::cout << "\n";
    int *areas = new int[no];
    for (int i = 0; i < no; i++)
    {
        areas[i] = nxt[i] - prev[i] - 1;
        areas[i] *= input[i];
    }
    int max = 0;
    for (int i = 0; i < no; i++)
    {
        if (areas[i] > max)
        {
            max = areas[i];
        }
        // std::cout << areas[i] << " ";
    }
    std::cout << "\n"
              << max << "\n";

    return 0;
}