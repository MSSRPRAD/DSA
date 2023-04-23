#include<iostream>
#include<queue>
#include<vector>

int main(void){
    int n, k;
    std::cin>>n>>k;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cin>>matrix[i][j];
        }
    }

    std::priority_queue<int, std::vector<int>, std::greater<int>> priority_queue;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            priority_queue.push(matrix[i][j]);
        }
    }
    while(k>1){
        priority_queue.pop();
        k--;
    }
    int ans = priority_queue.top();    
    std::cout<<ans;

    return 0;
}