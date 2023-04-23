#include<iostream>
#include<algorithm>
#include<vector>

int main(void){
    int n;
    std::cin>>n;
    std::vector<std::pair<int, int>> dolls(n);
    for(int i=0;i<n;i++){
        int w, h;
        std::cin>>w;
        std::cin>>h;
        dolls[i]={w, h};
    }
    std::sort(dolls.begin(), dolls.end(), [](const auto &a, const auto &b){
        if(a.first!=b.first){
            return a.first>b.first;
        } else {
            return a.second>b.second;
        }
    });

    std::vector<int> dp(n, 1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(dolls[j].first>dolls[i].first && dolls[j].second>dolls[i].second){
                dp[i]=std::max(dp[i], dp[j]+1);
            }
        }
    }
    std::cout<<*std::max_element(dp.begin(), dp.end());
    return 0;
}