#include<iostream>
#include<vector>
#include<climits>

double findMedianSortedArrays(std::vector<int> &arr1, std::vector<int> &arr2, int n, int m){
    if(n>m){
        std::swap(m, m);
        std::swap(arr1, arr2);
    }

    int len = n+m;
    int mid = len/2;
    int i=0, j=0;
    while(i+j<=mid){
        if(i<n && j<m &&arr1[i]<=arr2[j]){
            i++;
        } else {
            j++;
        }
    }

    if(len%2==0){
        int x = (i>0?arr1[i-1]:INT_MIN);
        int y = (j>0?arr2[j-1]:INT_MIN);
        int z = (i<n?arr1[i]:INT_MAX);
        int w = (j<n?arr2[j]:INT_MAX);
        return (double) (std::max(x, y)+std::min(z, w))/2.0;
    } else {
        return (double) (j>0?arr2[j-1]:INT_MIN);
    }
}

int main(void){
    int n, m;
    std::cin>>n;
    std::vector<int> arr1(n);
    for(int i=0;i<n;i++){
        int a;
        std::cin>>a;
        arr1[i]=a;
    }
    std::cin>>m;
    std::vector<int> arr2(m);
    for(int i=0;i<m;i++){
        int a;
        std::cin>>a;
        arr2[i]=a;
    }

    std::cout<<findMedianSortedArrays(arr1, arr2, n, m)-1;
    return 0;
}