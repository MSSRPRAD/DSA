#include<iostream>
#include<unordered_map>

long count_subarrays(long arr[], long n, long k){
    long result = 0, current_sum = 0;
    std::unordered_map<long,long> hash_map;

    for(int i=0;i<n;i++){
        // Subtract k from each element and add it to current sum
        current_sum += arr[i]-k;
        // If current_sum is 0, we add the count
        if(current_sum==0){result++;}

        // Check if current_sum has occured before.
        // If it has, add it's frequency to res
        if(hash_map.find(current_sum)!=hash_map.end()){
            result += hash_map[current_sum];
        }

        hash_map[current_sum]++;
    }

    return result;
}

int main(void) {
    long n,k;
    std::cin>>n;
    std::cin>>k;
    long arr[n];
    for(long i=0;i<n;i++){
        long temp;
        std::cin>>temp;
        arr[i]=temp;
    }
    std::cout<<count_subarrays(arr,n,k);
    return 0;
}