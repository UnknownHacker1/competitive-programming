/*
 * Fancy Fence  [1402A]
 * Problem:  https://codeforces.com/problemset/problem/1402/A
 * Verdict:  ACCEPTED        Solved: 2024-03-23
 * Language: C++17 (GCC 7-32)
 * Runtime:  139 ms     Memory: 10400 KB
 * Tags:     *special, data structures, dsu, implementation, math, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1402/submission/252934304
 */

#include <bits/stdc++.h> 
using namespace std;
#define int long long
using ll = long long;    
const int N = 1e5 + 3, mod = 1e9 + 7;
pair<int,ll>sz[N];
ll ans,cnt;
int par[N], h[N], w[N], n;
int find_set(int a){
    if(a == par[a]) return a;
    return par[a] = find_set(par[a]);
}
void merge(int a, int b){
    a = find_set(a), b = find_set(b);
    if(a == b) return;
    if(sz[a].first < sz[b].first) swap(a, b);
    par[b] = a;
    sz[a].first += sz[b].first;
    cnt -= sz[a].second*(sz[a].second + 1) / 2 + sz[b].second*(sz[b].second + 1) / 2;
    sz[a].second += sz[b].second;
    sz[a].second %= mod;
    cnt += sz[a].second*(sz[a].second + 1) / 2;
    cnt = (cnt + mod*mod) % mod;
}
void make_set(int i){
    par[i] = i;
    sz[i].first = 1;
    sz[i].second = w[i];
    cnt += w[i]*1ll*(w[i] + 1) / 2;
    cnt %= mod;
    if(i > 0 && sz[i-1].first){
        merge(i, i - 1);
    }
    if(i + 1 < n && sz[i+1].first){
        merge(i, i + 1);
    }
}
ll sum(ll l, ll r){
    return (r*(r+1) - l*(l-1))>>1;
}
map<int,vector<int>>occ{};
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);  
    cin>>n;
    for(int i = 0; i < n; i++)cin>>h[i],occ[h[i]].push_back(i);
    for(int i = 0; i < n; i++)cin>>w[i];
    sort(h,h+n,greater<int>());
    h[n] = 0;
    for(int i = 0; i < n; i++){  
        if(h[i] == h[i + 1]) continue;
        vector<int>&v = occ[h[i]];
        for(int x : v){
            make_set(x);
        } 
        ans += (sum(h[i + 1] + 1, h[i])%mod * cnt%mod)%mod;
        ans %= mod;
    } 
    //cout<<"y";
    cout<<ans;
    return 0;
}