#include<map>
#include<set>
#include<unordered_map>
#include<iostream>
#include<vector>
#include<algorithm>

int fun(std::set<int> &s1, std::set<int> &s2){
    int count = 0, i = 0, ssize = s2.size();
    auto it1 = s1.begin();
    auto it2 = s2.begin();
    while(it1!=s1.end() && it2!=s2.end()){
        if(*it1<*it2){
            count += ssize - i;
            it1++;
        } else {
            while(it2 != s2.end() && *it1 >= *it2){
                it2++;
                i++;
            }
        }
    }
    return count;
}

void count_pairs(std::map<int, std::set<int>> &mpx,std::map<int, std::set<int>> &mpy){
    int pairs = 0;
    for (auto x : mpx){
        auto y : mpy.find(x.first());
        if(y!=mpy.end()){
            pairs += fun(x.second, y.second);
        }
    }
    std::cout << pairs << std::endl;
    return;
}

void xNyArrays(int n, std::vector<int> arr, int x, int y){
    std::map<int, std::set<int>> mpx,mpy;
    for (int i = 0; i < n;i++){
        mpx[arr[i] - x * i] = i;
        mpx[arr[i] - y * i] = i;
    }
    count_pairs(mpx, mpy);
    return;
}

int main(void){
    int n;
    std::vector<int> arr;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        arr.push_back(a);
    }
    std::sort(arr.begin(), arr.end());
    
    std::cin >> x;
    std::cin >> y;

    xNyArrays(n, arr, x, y);

    return 0;
}