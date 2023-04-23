#include<iostream>
#include<vector>
#include<algorithm>

std::vector<int> pancakeSort(std::vector<int> &arr, int n){
    std::vector<int> sorted;

    for(int i=n;i>0;i--){
        auto max_it = std::max_element(arr.begin(), arr.begin()+i);
        int max_idx = max_it-arr.begin();
        if(max_idx==i-1){
            continue;
        }
        if(max_idx != 0){
            std::reverse(arr.begin(), arr.begin()+max_idx+1);
            sorted.push_back(max_idx+1);
        }
        std::reverse(arr.begin(), arr.begin()+1);
        sorted.push_back(i);
    }
    return sorted;
}



int main(void){
    int n;
    std::cin>>n;
    std::vector<int> arr(n);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    std::vector<int> sorted = pancakeSort(arr, n);
    for(auto i: sorted){
        std::cout<<i<<std::endl;
    }
    return 0;
}