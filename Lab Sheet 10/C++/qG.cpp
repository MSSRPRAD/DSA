#include<iostream>
#include<deque>

int main(void){
    int n, k;
    std::cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    std::deque<int> deque;
    for(int i=0;i<n;i++){
        while(!deque.empty() && arr[deque.back()]<arr[i]){
            deque.pop_back();
        }
        deque.push_back(i);
        if(deque.front()<= i-k){
            deque.pop_front();
        }
        if(i>=k-1){
            std::cout<<arr[deque.front()]<<" ";
        }
    }
    return 0;
}