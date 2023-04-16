#include<iostream>
#include<stack>
#include<vector>

int sum_of_subarray_ranges(int a[], int n) {
    int ans = 0;
    std::stack<int> s;
    std::vector<int> left, right;
    for(int i = 0; i < n; i++) {
        while(!s.empty() && a[s.top()] > a[i]) {
            right[s.top()] = i - 1;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()) {
        right[s.top()] = n - 1;
        s.pop();
    }
    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty() && a[s.top()] >= a[i]) {
            left[s.top()] = i + 1;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()) {
        left[s.top()] = 0;
        s.pop();
    }
    for(int i = 0; i < n; i++) {
        ans += a[i] * (i - left[i] + 1) * (right[i] - i + 1);
    }
    return ans;
}


int main(void){
    int n;
    std::cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        int a;
        std::cin>>a;
        arr[i]=a;
    }
    std::cout<<sum_of_subarray_ranges(arr,n);
    return 0;
}