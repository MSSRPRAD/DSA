#include<iostream>
#include<set>
#include<vector>

int main(void){
    int n;
    std::cin>>n;
    std::vector<int> arr(n);
    for(int i=0;i<n;i++){
        int a;
        std::cin>>a;
        arr[i]=a;
    }

    int count=0;
    std::set<int, std::greater<int>> set;
    for(int i=0;i<n;i++){
        count+=std::distance(set.begin(), set.lower_bound(arr[i]));
        set.insert(arr[i]);
    }
    std::cout<<count;
}