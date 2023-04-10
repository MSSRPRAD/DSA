#include<iostream>
#include<bits/stdc++.h>

int main(void){
    int n, m, k;
    std::cin >> n;
    std::cin >> m;
    std::cin >> k;
    int arr[n];
    for (int i = 0; i < n;i++){
        int a;
        std::cin >> a;
        arr[i] = a;
    }

    for (int i = 0; i <= n - m;i++){
        std::unordered_map<int, int> hash_map;
        for (int j = i; j < i + m; j++)
        {
            hash_map[arr[j]]++;
        }
        int max_element = -999;
        bool found = false;
        for(auto j:hash_map){
            if(j.second==k){
                max_element = std::max(max_element, j.first);
                found = true;
            }
        }
        found ? std::cout << max_element << std::endl : std::cout<<"-1\n";
    }

    return 0;
}