/*
 * Explorer  [104390B]
 * Problem:  Gym/ICPC contest 104390 - problem B
 * Verdict:  ACCEPTED        Solved: 2023-07-10
 * Language: C++20 (GCC 11-64)
 * Runtime:  327 ms     Memory: 70400 KB
 * Tags:     n/a
 * Author:   BidoTeima
 * Source:   https://codeforces.com/gym/104390/submission/213113936
 */

#include <bits/stdc++.h>
using namespace std; 
using ll = int64_t;
const int N = 5e5 + 3, mod = 1e9 + 7;
vector<int>adj[N];
ll fact[N];
ll dfs(int node, int prev){
    ll ret = fact[(int)adj[node].size() - (prev == -1? 0 : 1)];
    for(int child : adj[node]){
        if(child != prev){
            ret = (ret * dfs(child, node)) % mod;
        }
    }
    return ret;
}
int main()
{ 
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);   
    fact[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = (fact[i - 1] * i) % mod;
    }
    int n;
    cin>>n;
    int a,b;
    for(int i = 1; i < n; i++){
        cin>>a>>b; 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin>>a;
    cout<<dfs(a, -1);
    return 0;
}