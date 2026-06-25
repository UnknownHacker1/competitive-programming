/*
 * Ralph and Mushrooms  [894E]
 * Problem:  https://codeforces.com/problemset/problem/894/E
 * Verdict:  ACCEPTED        Solved: 2022-06-09
 * Language: C++20 (GCC 11-64)
 * Runtime:  1294 ms     Memory: 235200 KB
 * Tags:     dp, graphs
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/894/submission/160018752
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
vector<pair<int,int>>adj[(int)1e6+3],adj_rev[(int)1e6+3],adj_scc[(int)1e6+3];
vector<int>topo;
vector<bool>vis;
vector<int>scc;
int scc_count;
ll mushrooms_scc[(int)1e6+3];
void dfs_topo(int node){
    if(vis[node])return;
    vis[node]=1;
    for(auto p:adj[node]){
        dfs_topo(p.first);
    }
    topo.push_back(node);
}
void dfs_scc(int node){
    if(vis[node])return;
    vis[node]=1;
    scc.push_back(node);
    for(auto p:adj_rev[node]){
        dfs_scc(p.first);
    }
} 
ll calc(double x){
    double n = (sqrt(8*x+1)-1.0)/2.0;
    n=floor(n);
    return ll(x*(n+1)-(n*(n+1)*(2*n+1)/12+n*(n+1)/4));
}
ll dp[(int)1e6+3];
ll dfs_dag(int node){
    if(dp[node]!=-1)return dp[node];
    ll ret = 0;
    for(auto u:adj_scc[node]){
        ret=max(ret,dfs_dag(u.first)+u.second);
    }
    return dp[node]=ret+mushrooms_scc[node];
}
int main()
{
    ACPLS(); 
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj_rev[b].push_back({a,w});
    }
    int s;
    cin>>s;
    vis.assign(n+5,false);
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs_topo(i);
        }
    }
    vis.assign(n+5,false);
    reverse(topo.begin(),topo.end());
    int scc_id[n+3];
    memset(scc_id,-1,sizeof(scc_id));
    for(int node:topo){
        if(!vis[node]){
            scc.clear();
            dfs_scc(node);
            for(int u:scc){
                scc_id[u]=scc_count;
            }
            for(int v:scc){
                for(auto u:adj[v]){
                    if(scc_id[u.first]==scc_count){
                        mushrooms_scc[scc_count]+=calc(u.second);
                    }
                }
            }
            scc_count++;
        }
    }
    for(int i = 1; i <= n; i++){
        for(auto u:adj[i]){
            if(scc_id[i]!=scc_id[u.first]){
                adj_scc[scc_id[i]].push_back({scc_id[u.first],u.second});
            }
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<dfs_dag(scc_id[s]);
}
