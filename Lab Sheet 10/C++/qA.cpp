#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

int maxSubarraySum(std::vector<int>& nums){
    int max_sum = INT_MIN;
    int curr_sum = 0;
    for(int num: nums){
        curr_sum = std::max(curr_sum+num, num);
        max_sum = std::max(max_sum, curr_sum);
    }
    return max_sum;
}

int main(void){
    int n;
    std::cin>>n;
    std::vector<int> nums(n);
    for(int i=0;i<n;i++){
        int a;
        std::cin>>a;
        nums[i]=a;
    }
    std::cout<<maxSubarraySum(nums);
    return 0;
}