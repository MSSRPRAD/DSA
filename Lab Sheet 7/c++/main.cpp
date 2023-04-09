#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void heapify(vector <int> &v,int i,int heapsize){

    int l=2*i+1;
    int r=2*i+2;
    int largest=i;

    if (l<heapsize && v[l]>v[largest]){

        largest= l;
    }

    if (r<heapsize && v[r]>v[largest]){

        largest= r;
    }

    if (largest!=i){

        swap(v[i],v[largest]);
        heapify(v,largest,heapsize);
    }
}   

int main(){
    
    int n,m;
    cin>>n;
    cin>>m;
    vector<int>v;

    for(int i=0;i<n;i++){

        int x;
        cin>>x;
        v.push_back(x);
    }

    // Make a heap using data from v
    make_heap(v.begin(),v.end());
    sort_heap(v.begin(), v.end());
    reverse(v.begin(),v.end());

    while (m!=0){
        v[0]=v[0]/2;
        heapify(v,0,n);
        m--;
    }

    int sum=0;
    for(int i=0;i<n;i++){
        sum+=v[i];
    }
    cout<<sum;
    return 0;
}