#include<iostream>
#include<unordered_set>

int main(void){
    int n, k;
    std::cin>>n;
    std::cin>>k;
    std::unordered_set<int> points;
    for(int i=0;i<n;i++){
        int a;
        std::cin>>a;
        points.insert(a);
    }
    int count = 0;
    for(auto x: points) {
        if(points.count(x+k)){
            count++;
        }
    }
    std::cout<<count<<std::endl;

    return 0;
}