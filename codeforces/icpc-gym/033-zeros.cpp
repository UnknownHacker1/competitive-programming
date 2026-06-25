/*
 * Zeros  [103148A]
 * Problem:  Gym/ICPC contest 103148 - problem A
 * Verdict:  ACCEPTED        Solved: 2023-12-09
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     n/a
 * Author:   BidoTeima
 * Source:   https://codeforces.com/gym/103148/submission/236488833
 */

#include <bits/stdc++.h> 

using namespace std;
typedef long long ll;   
ll f(ll a, ll b, int base){
    ll ret = 0;
    for(ll c = base, i = 1; c <= 1e18; c *= base, i++){
        ll lo = 1, hi = 2e18 / c, mid;
        bool yes=0;
        while(lo <= hi){
            mid=(lo+hi)>>1;
            if(a <= mid * c && mid * c <= b){
                yes=1;
                break;
            }
            else if(mid * c < a){
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        if(yes)ret=i;
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);  
    ll a,b;
    cin>>a>>b; 
    cout<<min(f(a, b, 2), f(a, b, 5));
    return 0;
}