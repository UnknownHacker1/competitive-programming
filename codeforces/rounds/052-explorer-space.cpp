/*
 * Explorer Space  [1517D]
 * Problem:  https://codeforces.com/problemset/problem/1517/D
 * Verdict:  ACCEPTED        Solved: 2022-08-28
 * Language: C++20 (GCC 11-64)
 * Runtime:  1855 ms     Memory: 85500 KB
 * Tags:     dp, graphs, shortest paths
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1517/submission/170006573
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename t1>
using ordered_set = tree<t1, null_type,less<t1>, rb_tree_tag,tree_order_statistics_node_update>;
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
#define tc         \
    int tttttt,subtask;    \
    cin >> tttttt /*>> subtask*/; \
    while (tttttt--)
#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end()
int main()
{
    ACPLS();
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>adj[n+1][m+1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m-1; j++){
            int w;
            cin>>w;
            adj[i][j].push_back({i,j+1,w});
            adj[i][j+1].push_back({i,j,w});
        }
    }
    for(int i = 1; i <= n-1; i++){
        for(int j = 1; j <= m; j++){
            int w;
            cin>>w;
            adj[i][j].push_back({i+1,j,w});
            adj[i+1][j].push_back({i,j,w});
        }
    } 
    if(k&1){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cout<<"-1 ";
            }
            cout<<'\n';
        }
        return 0;
    }
    int dp[n+1][m+1][k+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j][0] = 0;
            for(int l = 1; l <= k; l++){
                dp[i][j][l] = 1e9;
            }
        }
    }
    for(int l = 1; l <= k; l++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){ 
                for(auto edge : adj[i][j]){
                    dp[i][j][l] = min(dp[i][j][l],dp[edge[0]][edge[1]][l - 1] + edge[2]);
                }    
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout<<2*dp[i][j][k/2]<<' ';
        }
        cout<<'\n';
    }
}   