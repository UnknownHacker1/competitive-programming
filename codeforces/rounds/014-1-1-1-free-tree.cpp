/*
 * 1-1-1, Free Tree!  [2126F]
 * Problem:  https://codeforces.com/problemset/problem/2126/F
 * Verdict:  ACCEPTED        Solved: 2025-10-23
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  765 ms     Memory: 74800 KB
 * Tags:     brute force, data structures, dfs and similar, graphs, implementation, trees
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2126/submission/345425372
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;    

const int N = 2e5 + 3;

int par[N],a[N],cost[N],costNode[N];
vector<pair<int,int>>adj[N];
map<int,ll>sum[N]; // sum[v][c] -> sum of children of v w/ color c

void dfs(int node, int p = -1){ 
    par[node] = p;
    for(auto& [child, edge] : adj[node]){
        if(child == p) continue;

        sum[node][a[child]] += cost[edge];
        costNode[child] = cost[edge];

        dfs(child, node);
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);      

    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;

        for(int i = 1; i <= n; i++) 
            cin >> a[i],par[i]=-1,sum[i].clear(),adj[i].clear();

        ll tot = 0;
        for(int i = 0; i + 1 < n; i++){
            int u, v, c;
            cin >> u >> v >> c;
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
            cost[i] = c;

            if(a[u] != a[v])
                tot += c;
        }

        dfs(1);
        /*for(int i = 1; i <= n; i++){
            cout << par[i] << ' ';
        }cout << '\n';*/
        while(q--) {
            int v, x;
            cin >> v >> x;

            int cur = a[v];
            a[v] = x;

            if(cur == x){
                cout << tot << '\n';
                continue;
            }

            tot += sum[v][cur] - sum[v][x];
            
            if(par[v] != -1){ 
                // cout << v << ": " << costNode[v] << '\n';
                if(a[par[v]] == x){
                    tot -= costNode[v];
                }else if(a[par[v]] == cur){
                    tot += costNode[v];
                }
                sum[par[v]][x] += costNode[v];
                sum[par[v]][cur] -= costNode[v];

            }else{
                // cout << v << ": gigachad. Or is it?\n";
            }
            cout << tot << '\n';
        }
        // cout << '\n';
        
    }
    
    return 0;
}
