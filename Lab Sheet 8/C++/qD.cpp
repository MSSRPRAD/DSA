#include<bits/stdc++.h>

int main(void){

    long long n, q;
    std::cin >> n;
    std::cin >> q;
    std::set<long long, std::greater<long long>> setd;
    std::set<long long> seta;
    for (long long i = 0; i < q; i++)
    {
        long long k;
        long long type;
        std::cin >> type;
        std::cin >> k;
        switch (type)
        {
            case 1:
                if(seta.count(k)==1) {
                    seta.erase(k);
                    setd.erase(k);
                }
                else {
                    seta.insert(k);
                    setd.insert(k);
                }
                break;
            case 2:
                if (seta.lower_bound(k)!=seta.end()){
                    std::cout << *seta.lower_bound(k) << std::endl;
                } else {
                    std::cout << -1<<std::endl;
                }
                break;
            case 3:
                if (setd.lower_bound(k) != setd.end())
                {
                    std::cout << *setd.lower_bound(k) << std::endl;
                }
                else
                {
                    std::cout << -1<<std::endl;
                }
                break;
            default:
                std::cout << "Some Mistake Happened!\n";
                break;
        }
    }

    return 0;
}