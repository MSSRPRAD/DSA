#include<iostream>
#include<bits/stdc++.h>

int main(void){
    int n, k;
    std::cin >> n;
    std::cin >> k;
    std::unordered_map<int, int> hash_map;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a;
        std::cin >> b;
        hash_map[b]++;
    }
    
    for (int i = 1; i <= k; i++)
    {
        if(hash_map[i]<=1){
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}