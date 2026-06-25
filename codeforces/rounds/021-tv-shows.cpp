/*
 * TV Shows  [1061D]
 * Problem:  https://codeforces.com/problemset/problem/1061/D
 * Verdict:  ACCEPTED        Solved: 2025-02-17
 * Language: C++20 (GCC 13-64)
 * Runtime:  171 ms     Memory: 4500 KB
 * Tags:     data structures, greedy, implementation, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1061/submission/306589615
 */

#include <bits/stdc++.h>
using namespace std; 

using ll = long long;
const int mod = 1e9 + 7;
#define int long long
int32_t main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    int n,x,y;
    cin>>n>>x>>y;
    pair<int,int>show[n];
    for(auto&i:show)cin>>i.first>>i.second;
    sort(show,show+n);
    multiset<pair<int,int>>ms;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int l = show[i].first, r = show[i].second;  
        // find one that maximizes x - y * (l - ms_r)
        // i.e. find one w/ max ms_r such that it's < l 
        // i.e. find one w/ max ms_r such that it's <= l - 1
        auto goodIt = ms.upper_bound({l - 1, 1e9+1}); // guaranteed to return first element >= l
        if(goodIt != ms.begin() && y * (l - prev(goodIt)->first) < x){ 
            goodIt = prev(goodIt);
            int oldL = goodIt->second;
            // cout << oldL << '\n';
            ms.erase(goodIt);
            ms.insert({r, oldL});
        }else{
            // cout << l << '\n';
            ms.insert({r, l});
        }
    }
    for(auto& it : ms){
        ans += y * 1ll * (it.first - it.second) + x;
        ans %= mod;
    }
    cout << ans;
	return 0;
}
