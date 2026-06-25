/*
 * Where is the Pizza?  [1670C]
 * Problem:  https://codeforces.com/problemset/problem/1670/C
 * Verdict:  ACCEPTED        Solved: 2025-03-03
 * Language: C++17 (GCC 7-32)
 * Runtime:  140 ms     Memory: 2400 KB
 * Tags:     data structures, dfs and similar, dsu, graphs, implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1670/submission/308777148
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;  
const int mod = 1e9 + 7;
const int N = 1e5 + 3;
bool vis[N];
vector<int>adj[N];
void dfs(int node){  
    if(vis[node])return;
    vis[node]=1;
    for(int child : adj[node]){
        dfs(child);
    }
}
int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    int t;
    cin>>t;
    while(t--){ 
        int n;
        cin>>n; 
        for(int i = 1; i <= n; i++)vis[i]=0,adj[i].clear();
        int a[n],b[n],c[n];
        for(auto&i:a)cin>>i;
        for(auto&i:b)cin>>i;
        for(auto&i:c)cin>>i; 
        for(int i = 0; i < n; i++){
            if(!c[i]){
                adj[a[i]].push_back(b[i]);
                adj[b[i]].push_back(a[i]);
            }
        }
        for(int i = 0; i < n; i++){
            if(c[i]){
                dfs(c[i]);
            }
            if(a[i] == b[i]){
                dfs(a[i]);
            }
        } 
        ll ans = 1;
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                dfs(i);
                ans=(ans*2)%mod;
            }
        }  
        cout<<ans<<'\n';
    }
	return 0;
}
