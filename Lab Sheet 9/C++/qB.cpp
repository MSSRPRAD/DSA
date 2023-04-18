#include<iostream>
#include<string>
#include<vector>

using namespace std;

std::vector<int> plates_between_candles(std::string input, std::vector<std::vector<int>> queries, int q, int n){
    std::vector<int> ans;
    std::vector<int> prev(n);
    std::vector<int> next(n);
    std::vector<int> pre_sum(n);

    int p=-1,nxt=-1;

    // Calculating prev candle upto this index
    for(int i=0;i<n;i++){
        if(input[i]=='|'){
            p=i;
        }
        prev[i]=p;
    }
    // Calculating the next candle from this index
    for(int i=n-1;i>-1;i--){
        if(input[i]=='|'){
            nxt = i;
        }
        next[i]=nxt;
    }

    int count=0;

    // Calculating the number of stars between these indices
    for(int i=0;i<n;i++){
        if(input[i]=='*'){
            count++;
        }
        pre_sum[i]=count;
    }
    // Calculating answer
    for(int i=0;i<q;i++){
        int x = queries[i][0];
        int y = queries[i][1];
        // Position of left and right candle
        int right = prev[y];
        int left = next[x];

        if(left==-1||right==-1||left>right){
            ans.push_back(0);
        } else {
            ans.push_back(pre_sum[right]-pre_sum[left]);
        }
    }
    return ans;
}

int main(){
    int n,q;
    cin>>n>>q;

    std::string input;
    cin>>input;

    std::vector<std::vector<int>> queries(q,vector<int>(2));
    for(int i=0;i<q;i++){
        std::cin>>queries[i][0]>>queries[i][1];
    }
    std::vector<int> res = plates_between_candles(input,queries,q, n);
    for(auto x: res){
        std::cout<<x<<std::endl;
    }
    return 0;

}