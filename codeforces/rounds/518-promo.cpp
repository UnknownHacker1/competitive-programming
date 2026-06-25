/*
 * Promo  [1697B]
 * Problem:  https://codeforces.com/problemset/problem/1697/B
 * Verdict:  ACCEPTED        Solved: 2025-03-17
 * Language: C++17 (GCC 7-32)
 * Runtime:  296 ms     Memory: 100 KB
 * Tags:     greedy, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1697/submission/311024319
 */

#include <bits/stdc++.h>
using namespace std; 
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    int n,q;
    cin>>n>>q;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    sort(a,a+n,greater<ll>());
    for(int i = 1; i < n; i++) a[i] += a[i - 1];
    while(q--){
        int x,y;
        cin>>x>>y;
        --x,--y;
        if(x==y)cout<<a[x]<<'\n';
        else cout<<a[x]-a[x-y-1]<<'\n';
    }
    return 0;
}