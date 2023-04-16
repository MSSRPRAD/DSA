#include<iostream>

int main(void){
    long m,k,n;
    
    long p,q;
    std::cin>>m;
    std::cin>>k;
    std::cin>>n;
    std::cin>>p;
    long first[m][k], second[k][n], result[m][n];
    for(long i=0;i<m;i++){
        for(long j=0;j<k;j++){
            first[i][j] = 0;
        }
    }
    for(long i=0;i<k;i++){
        for(long j=0;j<n;j++){
            second[i][j] = 0;
        }
    }    
    for(long i=0;i<m;i++){
        for(long j=0;j<n;j++){
            result[i][j] = 0;
        }
    }
    for(long i=0;i<p;i++){
        long a,b,c;
        std::cin>>a;
        std::cin>>b;
        std::cin>>c;
        first[a-1][b-1] = c;
    }
    std::cin>>q;
    for(long i=0;i<q;i++){
        long a,b,c;
        std::cin>>a;
        std::cin>>b;
        std::cin>>c;
        second[a-1][b-1] = c;
    }
    
    for(long i=0;i<m;i++){
        for(long j=0;j<n;j++){
            for(long x=0; x<k; x++){
                result[i][j] += first[i][x] * second[x][j];
            }
        }
    }

    // Displaying the result
    std::cout << "\nOutput:\n";
    long count=0;
    for(long i=0;i<m;i++){
        for(long j=0;j<n;j++){
            if(result[i][j]!=0){
                count++;
            }
        }
    }
    std::cout<<count<<std::endl;
    for(long i=0; i<m; i++)
    {
        for(long j=0; j<n; j++){
            if(result[i][j]!=0){
                std::cout<<i+1<<" "<<j+1<<" "<<result[i][j]<<std::endl;
            }
        }
    }

    return 0;
}