#include<iostream>
#include<vector>
#include<algorithm>

int main(void){
    int n, m;
    std::cin>>n>>m;
    std::vector<int> arr1(n), arr2(m);
    for(int i=0;i<n;i++){
        std::cin>>arr1[i];
    }
    for(int i=0;i<n;i++){
        std::cin>>arr2[i];
    }

    std::vector<int> C, D;

    for(int i=0;i<n;i++){
        if(std::find(arr2.begin(), arr2.end(), arr1[i])!=arr2.end()){
            C.push_back(arr1[i]);
        }
    }

    std::sort(C.begin(), C.end(), [&](int a, int b){
        return std::find(arr2.begin(), arr2.end(), a)<std::find(arr2.begin(), arr2.end(), b);
    });

    for(int i=0;i<n;i++){
        if(std::find(arr2.begin(), arr2.end(), arr1[i])!=arr2.end()){
            C.push_back(arr1[i]);
        }
    }

    std::sort(D.begin(), D.end());

    std::vector<int> ans;

    for(int i=0;i<C.size();i++){
        ans.push_back(C[i]);
    }
    for(int i=0;i<D.size();i++){
        ans.push_back(D[i]);
    }

    for(int i=0;i<ans.size();i++){
        std::cout<<ans[i]<<" ";
    }

    return 0;
}