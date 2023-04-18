#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

typedef long long ll;

int main(void){
    ll n;
    std::cin>>n;
    std::vector<std::pair<ll,ll>> trains(n);
    for(ll i=0;i<n;i++){
        ll a,b;
        std::cin>>a;
        std::cin>>b;
        trains[i].first=a;
        trains[i].second=b;
    }
    std::sort(trains.begin(), trains.end());

    ll platforms = 0;
    std::priority_queue<ll, std::vector<ll>, std::greater<int>> departures;

    for(ll i=0;i<n;i++){
        if(departures.empty()||trains[i].first<departures.top()) {
            platforms++;
        } else {
            departures.pop();
        }
        departures.push(trains[i].second);
    }

    std::cout<<platforms<<std::endl;
    return 0;
}