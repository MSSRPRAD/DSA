#include <iostream>
#include <stack>
#include <string>

int main()
{

    std::string input;
    std::cin >> input;

    std::stack<char> open;

    int ans = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '(')
        {
            open.push(')');
        }
        else
        {
            if (!open.empty())
            {
                open.pop();
            }
            else
            {
                ans++;
            }
        }
    }

    while (!open.empty())
    {
        ans++;
        open.pop();
    }
    std::cout << "\n"
              << ans << "\n";
    return 0;
}