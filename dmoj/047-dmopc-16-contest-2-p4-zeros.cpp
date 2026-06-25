/*
 * DMOPC '16 Contest 2 P4 - Zeros  [dmopc16c2p4]
 * Problem:  https://dmoj.ca/problem/dmopc16c2p4
 * Verdict:  ACCEPTED (7.0 pts)   Solved: 2022-02-15
 * Language: C++20
 * Runtime:  0.04999315 s     Memory: 3168.0 KB
 * Source:   https://dmoj.ca/src/4343870
 */

/// ya rab AC
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void ACPLS()
{
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
#define tc         \
    int tttttt,subtask;    \
    cin >> tttttt /*>> subtask*/; \
    while (tttttt--)
 
#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end()
ll f(ll n, ll p){
    ll ret=0;
    while(n){
        ret+=n/p;
        n/=p;
    }
    return ret;
}
int main()
{
    ACPLS();    
    ll a,b;
    cin>>a>>b;
    ll lo = 1, hi = 1e18, l = hi, r = lo;
    while(lo<=hi){
        ll mid = (lo+hi)/2;
        if(min(f(mid,2),f(mid,5))>=a){
            l=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    lo=1,hi=1e18;
    while(lo<=hi){
        ll mid = (lo+hi)/2;
        if(min(f(mid,2),f(mid,5))<=b){
            r=mid;
            lo=mid+1;
        }
        else hi=mid-1;
    }
    cout<<r-l+1;
}