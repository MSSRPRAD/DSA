#include <iostream>

typedef long long ll;

int main(void)
{
    ll n;
    std::cin >> n;
    ll petrol[n];
    ll cost[n];
    for (ll i = 0; i < n; i++)
    {
        ll a;
        std::cin >> a;
        petrol[i] = a;
    }
    for (ll i = 0; i < n; i++)
    {
        ll a;
        std::cin >> a;
        cost[i] = a;
    }

    ll start=0,end=1;
    ll current_petrol = petrol[start]-cost[start];
    // Loop through stations if
    // 1) All stations were not visited
    // 2) We reached first station with positive petrol
    while(end!=start || current_petrol<0){
        // If current petrol is negative we remove starting station from tour
        while(current_petrol<0 && start!=end){
            // Remove starting station,
            // Change start
            current_petrol -= petrol[start]-cost[start];
            start = (start+1)%n;
            // If 0 is being considered as start again we have no possible solution
            if(start==0){
                std::cout<<"-1\n";
                return 0;
            }
        }
        // Add a station to the tour
        current_petrol += petrol[end]-cost[end];
        end = (end+1)%n;
    }

    std::cout<<start<<"\n";

    // std::cout << start << std::endl;
    return 0;
}