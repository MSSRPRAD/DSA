#include<iostream>
#include<vector>

bool searchMatrix(std::vector<std::vector<int>> &arr, int num, int m, int n){

    int row = 1;
    int col = n;

    while(row <= m && col >= 1){
        if(arr[row-1][col-1]==num){
            return true;
        } else if (arr[row-1][col-1]>num){
            col--;
        } else {
            row++;
        }
    }

    return false;
}

int main(void){
    int m, n;
    std::cin>>m;
    std::cin>>n;
    std::vector<std::vector<int>> arr(m, std::vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int a;
            std::cin>>a;
            arr[i][j]=a;
        }
    }
    int num;
    std::cin>>num;
    if(searchMatrix(arr, num, m, n)) {
        std::cout<<"YES";
    } else {
        std::cout<<"NO";
    }
}