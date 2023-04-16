#include<iostream>
#include<queue>
#include<vector>
int main() {
    std::priority_queue<int, std::vector<int>, std::greater<int>> priority_queue;
    int n, sum=0;
    std::cin>>n;
    for(int i=0;i<n;i++) {
        int a;
        std::cin>>a;
        sum+=a;
        priority_queue.push(a);
    }
    while(sum<0){
        int a = priority_queue.top();
        sum -= a;
        priority_queue.pop();
        n--;
    }
    std::cout<<n;
}