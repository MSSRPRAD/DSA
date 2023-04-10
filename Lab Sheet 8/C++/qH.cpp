#include<bits/stdc++.h>

void count_substrings(std::string input){
    std::unordered_map<std::string, int> hash_map;
    std::unordered_set<int> int_set;

    int left = 0;
    int right = 9;
    while((left+9)<input.length()){
        std::string curr = input.substr(left,10);
        hash_map[curr]++;
        curr.push_back(input[left+9]);
        curr.erase(0, 1);
        left += 1;
    }

    bool cond = true;
    for (auto j : hash_map)
    {
        if(j.second>1){
            cond = false;
            if (int_set.find(j.second) == int_set.end())
            {
                std::cout << j.second << std::endl;
            }
            std::cout << j.first << std::endl;
            int_set.insert(j.second);
        }
    }

    if(cond)
        std::cout << 0 << std::endl;
}

int main(void){
    std::string input;
    std::cin >> input;
    count_substrings(input);
    return 0;
}