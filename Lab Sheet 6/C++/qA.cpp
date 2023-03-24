#include <iostream>

class MinStack
{

    int *arr;
    int topIndex;
    int minIndex;
    int *minArray;

public:
    MinStack()
    {
        this->arr = new int[1000];
        this->topIndex = -1;
        this->minArray = new int[1000];
        this->minIndex = -1;
    }

    void push(int val)
    {
        if (this->topIndex == -1)
        {
            this->minIndex = 0;
            this->minArray[minIndex] = val;
        }
        else
        {
            if (val <= this->minArray[this->minIndex])
            {
                this->minIndex += 1;
                this->minArray[minIndex] = val;
            }
        }
        this->topIndex += 1;
        this->arr[topIndex] = val;
    }
    void pop()
    {
        if (this->arr[this->topIndex] == this->minArray[this->minIndex])
        {
            this->minIndex -= 1;
        }
        this->topIndex--;
    }
    int top()
    {
        return this->arr[topIndex];
    }
    int minimum()
    {
        if (this->minIndex != -1)
        {
            return this->minArray[this->minIndex];
        }
        else
        {
            std::cout << "Error!";
            return -999;
        }
    }
};

int main(void)
{
    MinStack stack = MinStack();

    int no;
    std::cin >> no;

    for (int i = 0; i < no; i++)
    {
        int temp;
        std::cin >> temp;
        stack.push(temp);
    }

    int number;
    std::cin >> number;

    while (number--)
    {
        int operation;
        std::cin >> operation;

        switch (operation)
        {
        case 1:
            int temp;
            std::cin >> temp;
            stack.push(temp);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            std::cout << stack.top() << std::endl;
            break;
        case 4:
            int min = stack.minimum();
            std::cout << min << std::endl;
            break;
        }
    }
    return 0;
}