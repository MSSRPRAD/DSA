#include<iostream>
#include<map>
#include<string>
#include<algorithm>

void sort_passwords(std::string passwords[], int n){
    for (int i = 0; i < n;i++){
        std::sort(passwords[i].begin(), passwords[i].end());
    }
    return;
}

void total_anagrams(std::string passwords[], int n){
    std::map<std::string, int> map;
    for (int i = 0; i < n;i++){
        map[passwords[i]]++;
    }
    int total = 0;
    for (auto j : map)
    {
        total += j.second * (j.second - 1) / 2;
    }
    std::cout << total << std::endl;
    return;
}

int main(void){
    int n;
    std::cin >> n;
    std::string passwords[n];
    for (int i = 0; i < n;i++){
        std::cin >> passwords[i];
    }

    sort_passwords(passwords, n);
    total_anagrams(passwords, n);

    return 0;
}