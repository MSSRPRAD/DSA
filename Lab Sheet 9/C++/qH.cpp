#include<iostream>
#include<vector>

bool check(std::vector<int> vec, int mid, int n, int k){
    int sum=0,count=0;
    for(int i=0;i<n;i++){
        if(vec[i]>mid) return false;
        sum+=vec[i];
        if(sum>mid) {
            sum=vec[i];
            count++;
        }
    }
    count++;
    if (count<=k) return true;
    else return false;

    return false;
}

int binsearch(std::vector<int> vec, int start, int end, int n, int k) {
    int ans;
    while(start<=end){
        int mid=(start+end)/2;
        check(vec,mid,n,k)? ans=mid,end=mid-1:start=mid+1;
    }
    return ans;
}

int main(void){
    int n,k;
    std::cin>>n>>k;
    std::vector<int> vec;
    int pages = 0;
    for(int i=0;i<n;i++){
        int x;
        std::cin>>x;
        vec.push_back(x);
        pages+=x;
    }
    std::cout<<binsearch(vec,0,pages,n,k);
    return 0;
}
