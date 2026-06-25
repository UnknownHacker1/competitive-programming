/*
 * Book  [1572A]
 * Problem:  https://codeforces.com/problemset/problem/1572/A
 * Verdict:  ACCEPTED        Solved: 2022-06-12
 * Language: C++20 (GCC 11-64)
 * Runtime:  140 ms     Memory: 22300 KB
 * Tags:     binary search, brute force, data structures, dp, graphs, implementation, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1572/submission/160267907
 */

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
void moo(string fileName){
    freopen((fileName+".in").c_str(),"r",stdin);
    freopen((fileName+".out").c_str(),"w",stdout);
}
#define tc int tttt;cin>>tttt;while(tttt--)
vector<int>adj[(int)2e5+3],adj_rev[(int)2e5+3];
vector<int>vis;
bool invalid;
int dp[(int)2e5+3];
int dfs(int node){
    if(vis[node]){
        return dp[node];
    }
    vis[node]=1;
    int ret = 0;
    for(int child:adj[node]){
        ret=max(ret,dfs(child)+(child>=node));
    } 
    return dp[node]=ret;
}
vector<int>topo;
void dfs_topo(int node){
    if(vis[node])return;
    vis[node]=1;
    for(int child:adj[node]){
        dfs_topo(child);
    }
    topo.push_back(node);
}
vector<int>scc;
void dfs_scc(int node){
    if(vis[node])return;
    vis[node]=1;
    scc.push_back(node);
    for(int child:adj_rev[node]){
        dfs_scc(child);
    }
} 
int main()
{
    ACPLS(); 
tc{
    topo.clear();
    invalid=0;
    int n;
    cin>>n;
    vis.assign(n+5,0);
    for(int v = 1; v <= n; v++){
        adj[v].clear();
        adj_rev[v].clear();
    }
    for(int v = 1; v <= n; v++){
        dp[v]=0;
        vis[v]=0;
        int k;
        cin>>k;
        for(int j = 0; j < k; j++){
            int u;
            cin>>u;
            adj[v].push_back(u);
            adj_rev[u].push_back(v);
        }
    }
    vis.assign(n+5,false);
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs_topo(i);
        }
    }
    vis.assign(n+5,false);
    reverse(topo.begin(),topo.end());
    for(int node:topo){ 
        if(!vis[node]){
            scc.clear();
            dfs_scc(node);
            if(scc.size()>1){
                invalid=1;
                break;
            }
        }
    }
    if(invalid){
        cout<<"-1\n";
        continue;
    }
    vis.assign(n+3,0);
    int ans=0;
    for(int i = 1; i <= n; i++){
        if(!vis[i])ans=max(ans,dfs(i));
    }
    cout<<ans+1<<'\n';
}
}