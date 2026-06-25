/*
 * DMOPC '14 Contest 7 P4 - Sand Triangle  [dmopc14c7p4]
 * Problem:  https://dmoj.ca/problem/dmopc14c7p4
 * Verdict:  ACCEPTED (7.0 pts)   Solved: 2022-02-15
 * Language: C++20
 * Runtime:  0.166422676 s     Memory: 3168.0 KB
 * Source:   https://dmoj.ca/src/4343743
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
ll n;
ll l,r;
int check(ll x){
    l = x*(x-1)/2+1;
    r = x*(x-1)/2+x;
    if(n<l)
        return -1;
    else if(l<=n&&n<=r)
        return 0;
    return 1;
}
int main()
{
    ACPLS();  
    cin>>n;
    ll lo = 1, hi = 1e9;
    while(lo<=hi){
        ll mid=(lo+hi)/2;
        if(check(mid)==-1){
            hi=mid-1;
        }
        else if(!check(mid)){
            break;
        }
        else{
            lo=mid+1;
        }
    }
    cout<<r*(r+1)/2-l*(l-1)/2;
}