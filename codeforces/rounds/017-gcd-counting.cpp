/*
 * GCD Counting  [1101D]
 * Problem:  https://codeforces.com/problemset/problem/1101/D
 * Verdict:  ACCEPTED        Solved: 2025-03-06
 * Language: C++17 (GCC 7-32)
 * Runtime:  921 ms     Memory: 52800 KB
 * Tags:     data structures, dfs and similar, dp, number theory, trees
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1101/submission/309277013
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long; 
const int N = 2e5 + 3;
vector<int>primes[N];//primes for each
vector<int>adj[N];
int a[N],par[N],ans;
map<int,int>dp[N]; //dp[i][p] -> max path starting at i that all has prime p 
void dfs1(int node, int pa = -1){
    par[node]=pa;
    for(int child : adj[node]){
        if(child!=pa) dfs1(child, node);
    }
}
int dfs2(int node, int p){
    auto it = dp[node].find(p);
    if(it != dp[node].end()) return it->second;
    if(a[node]%p)return dp[node][p]=0;
    int ret = 0;
    for(int child : adj[node]){
        if(child!=par[node])ret=max(ret,dfs2(child,p));
    }
    return dp[node][p] = 1+ret;
} 
int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    for(int i = 2; i < N; i++){
        if(primes[i].size())continue; 
        for(int j = i; j < N; j += i){
            primes[j].push_back(i);
        }
    }
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1);
    for(int i = 1; i <= n; i++){
        for(int p : primes[a[i]]){
            dfs2(i,p);
            vector<int>v;
            for(int child : adj[i]){
                if(child != par[i]) v.push_back(dp[child][p]);
            }
            sort(v.begin(),v.end());
            ans=max(ans,dp[i][p]);
            if(v.size()>1)ans=max(ans,v.back()+v[(int)v.size()-2]+1);
        }
    }
    cout<<ans;
    return 0;
}
