/*
 * How Many Paths?  [1547G]
 * Problem:  https://codeforces.com/problemset/problem/1547/G
 * Verdict:  ACCEPTED        Solved: 2025-02-19
 * Language: C++20 (GCC 13-64)
 * Runtime:  733 ms     Memory: 105700 KB
 * Tags:     dfs and similar, dp, graphs, trees
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1547/submission/306889439
 */

#include <bits/stdc++.h>
using namespace std; 

using ll = long long;
const int N = 4e5 + 3;
vector<int>adj[N], adj_rev[N], adj_scc[N], adj_scc_rev[N];
bool vis[N];
vector<int>topo, scc;
int scc_cnt, scc_id[N];
void dfs_topo(int node){
    if(vis[node])return;
    vis[node] = 1;
    for(int u : adj[node]){
        dfs_topo(u);
    }
    topo.push_back(node);
}
void dfs_scc(int node){
    if(vis[node])return;
    vis[node]=1;
    scc.push_back(node);
    for(int u : adj_rev[node]){
        dfs_scc(u);
    }
}
int dp[N]; // {0, 1, 2}
int dfs_dag(int node){
    if(dp[node] != -1) return dp[node];
    if(node == scc_id[1]) return dp[node] = 1; // we account for special-ness in the main function
    int ret = 0;
    for(int u : adj_scc_rev[node]){
        ret += dfs_dag(u);
        if(ret > 2) ret = 2;
    }
    return dp[node] = ret;
}
int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            /*
            vector<int>adj[N], adj_rev[N], adj_scc[N], adj_scc_rev[N];
            bool vis[N];
            vector<int>topo, scc;
            int scc_cnt, scc_id[N];
            */
           adj[i].clear(),adj_rev[i].clear(),adj_scc[i].clear(),adj_scc_rev[i].clear();
           vis[i]=0;
           topo.clear(),scc.clear(),scc_cnt=0;
        }
        bool special[n + 1]{};
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            if(a == b){
                special[a] = 1;
            } else{
                adj[a].push_back(b);
                adj_rev[b].push_back(a);
            }
        }
        memset(vis, 0, sizeof(vis));
        topo.clear();
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                dfs_topo(i);
            }
        }
        memset(vis, 0, sizeof(vis));
        reverse(topo.begin(), topo.end());
        scc_cnt = 0;
        bool special_scc[n+1]{};
        for(int node : topo){
            if(!vis[node]){
                ++scc_cnt;
                scc.clear();
                dfs_scc(node);
                for(int u : scc){
                    scc_id[u] = scc_cnt;
                }
                if(scc.size() > 1 || special[scc.front()]){
                    special_scc[scc_cnt] = 1;
                } 
                else special_scc[scc_cnt] = 0; 
            }
            
        }
        for(int i = 1; i <= n; i++){
            for(int u : adj[i]){
                if(scc_id[i] != scc_id[u]){
                    adj_scc[scc_id[i]].push_back(scc_id[u]);
                    adj_scc_rev[scc_id[u]].push_back(scc_id[i]);
                }
            }
        }
        memset(dp, -1, sizeof(dp));
        for(int i = 1; i <= scc_cnt; i++){
            if(!dfs_dag(i)){
                special_scc[i] = 0;
            }
        }
        queue<int>q;
        for(int i = 1; i <= scc_cnt; i++){
            if(special_scc[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int u : adj_scc[node]){
                if(!special_scc[u]){
                    special_scc[u] = 1;
                    q.push(u);
                }
            }
        }
        for(int i = 1; i <= n; i++){
            if(special_scc[scc_id[i]]) cout << "-1 ";
            else cout << dfs_dag(scc_id[i]) << ' ';
        }
        cout<<'\n';
    }
	return 0;
}
