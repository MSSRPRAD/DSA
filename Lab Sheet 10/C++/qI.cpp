#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

int main(void){
    int n, m;
    std::cin>>n>>m;
    std::vector<int> arr1(n);
    std::vector<int> arr2(m);
    for(int i=0;i<n;i++){
        std::cin>>arr1[i];
    }
    for(int i=0;i<m;i++){
        std::cin>>arr2[i];
    }
    int sum_a = std::accumulate(arr1.begin(), arr1.end(), 0);
    int sum_b = std::accumulate(arr2.begin(), arr2.end(), 0);

    if((sum_a-sum_b)%2!=0){
        std::cout<<"NO!\n";
        return 0;
    }

    int target = (sum_a-sum_b)/2;

    std::sort(arr1.begin(), arr1.end());
    std::sort(arr2.begin(), arr2.end());

    int i=0, j=0;
    while(i<n && j<m){
        int diff = arr1[i]-arr2[j];
        if(diff==target){
            std::cout<<"YES!\n";
            return 0;
        } else if (diff<target){
            i++;
        } else {
            j++;
        }
    }

    std::cout<<"NO!\n";
    return 0;
}