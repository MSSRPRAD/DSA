#include<iostream>
#include<bits/stdc++.h>

int count_triangles(std::pair<int,int> P[], int n){
    std::map<std::pair<int, int>, int> map;
    int res = 0;

    for (int i = 0; i < n;i++ ){
        map.clear();

        // Find slope of all points wrt the current point
        for (int j = i + 1; j < n;j++){
            int X = P[i].first - P[j].first;
            int Y = P[i].second - P[j].second;

            int gcd = std::__gcd(X, Y);
            X /= gcd;
            Y /= gcd;  
            map[{X, Y}]++;
        }

        int num = n - i - 1;
        // Total no of triangles with current point
        res += num * (num - 1) / 2;
        // Subtract no of colinear triangles
        for(auto j: map){
            res -= j.second * (j.second - 1) / 2;
        }
    }

    return res;
}

int main(void){
    int n;
    std::cin>>n;
    std::pair<int, int> P[n];
    for (int i = 0; i < n;i++){
        int a, b;
        std::cin >> P[i].first;
        std::cin >> P[i].second;
    }
    std::cout << count_triangles(P, n);
    return 0;
}