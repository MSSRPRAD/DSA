#include <iostream>
#include <stack>
#include <string>

int main(void)
{
    std::string abspath;
    std::cin >> abspath;

    std::stack<std::string> dirs;
    std::string temp = "";

    for (int i = 0; i < abspath.size(); i++)
    {
        if (abspath[i] == '/')
        {
            if (!temp.empty())
            {
                dirs.push(temp);
                temp.clear();
            }
        }
        else
        {
            if (abspath[i] == '.')
            {
                if (i + 1 < abspath.size() && abspath[i + 1] == '.')
                {
                    dirs.pop();
                    i++;
                }
                else
                {
                    temp.clear();
                }
            }
            else
            {
                temp.push_back(abspath[i]);
            }
        }
    }
    if (!temp.empty())
    {
        dirs.push(temp);
        temp.clear();
    }
    std::stack<std::string> newdirs;
    std::cout << "START" << std::endl;
    while (!dirs.empty())
    {
        newdirs.push(dirs.top());
        std::cout << dirs.top() << "\n";
        dirs.pop();
    }
    std::cout << "START" << std::endl;
    if (newdirs.empty())
    {
        std::cout << "/";
    }
    while (!newdirs.empty())
    {
        std::cout << '/' << newdirs.top();
        newdirs.pop();
    }
    std::cout << std::endl;
    return 0;
}