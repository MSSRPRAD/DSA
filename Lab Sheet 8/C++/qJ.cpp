#include<bits/stdc++.h>

int main(void){

    int n,k;
    std::cin >> n;
    std::cin >> k;
    int arr[n];
    for (int i = 0; i < n;i++){
        int a;
        std::cin >> a;
        arr[i] = a;
    }

    std::unordered_map<int,int> hash_map;
    int curr_sum=0;
    int count=0;

    for(int i=0; i<n; i++)
    {
        curr_sum=curr_sum+arr[i];
        int x = curr_sum-k;

        if(curr_sum <= k)
            count++;

        while(x<=k)
        {
            count = count+hash_map[x];
            x = x+1;
        }
        hash_map[curr_sum]+=1;
    }
    
    std::cout << count;
    return 0;
}