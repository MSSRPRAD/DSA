#include<bits/stdc++.h>

bool compare(std::string a, std::string b){
    return a+b>b+a;
}

std::string largest_number(std::vector<std::string> &arr, int n){
    std::string result;
    result = accumulate(arr.begin(), arr.end(), std::string(""));
    if(result[0]=='0'){
        return "0";
    }
    return result;
}

int main(void){
    int n;
    std::cin>>n;
    std::vector<std::string> arr;
    for(int i=0;i<n;i++){
        std::string a;
        std::cin>>a;
        arr[i]=a;
    }
    std::cout<<largest_number(arr, n);
    return 0;
}