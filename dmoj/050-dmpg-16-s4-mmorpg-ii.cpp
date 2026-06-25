/*
 * DMPG '16 S4 - MMORPG II  [dmpg16s4]
 * Problem:  https://dmoj.ca/problem/dmpg16s4
 * Verdict:  ACCEPTED (12.0 pts)   Solved: 2023-07-03
 * Language: C++20
 * Runtime:  0.426393547 s     Memory: 19252.0 KB
 * Source:   https://dmoj.ca/src/5619448
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
const int N = 1e5 + 3;
int mod = 1e9 + 7;
vector<int>adj[N];
int sub[N];
ll fact[N];
ll POW(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ret;
}
int calc(int node){
    int ret = 1;
    for(int child : adj[node]){
        ret += calc(child);
    }
    return sub[node] = ret;
} 
ll inv(ll a){
    return POW(a, mod - 2);
}
ll dfs(int node){ 
    ll ret = fact[sub[node] - 1];
    for(int child : adj[node]){
        ret = (ret * dfs(child)) % mod;
        ret = (ret * inv(fact[sub[child]])) % mod;
    }
    return ret;
}
int main()
{ 
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);  
    int n;
    cin>>n;
    fact[0] = 1;
    for(int i = 1; i <= n; i++){
        int p;
        cin>>p;
        adj[p].push_back(i);
        fact[i] = (fact[i - 1] * i) % mod;
    }
    calc(0);
    cout<<dfs(0);
    return 0;
}