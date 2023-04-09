#include<iostream>
#include<vector>
#include<bits/stdc++.h>

int bad_subarrays(int *arr, int n){
    int count = 0;
    int current_sum = 0;
    std::unordered_map<int, int> hash_table;
    hash_table[0] = 1;

    for (int i = 0; i < n;i++){
        current_sum ^= arr[i];
        if(hash_table[current_sum ^ 0] > 0) {count += hash_table[current_sum ^ 0];}
        hash_table[current_sum]++;
    }

    return count;
}

int main(void){
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++){
        std::cin >> arr[i];
    }
    std::cout << bad_subarrays(arr, n);
    return 0;
}