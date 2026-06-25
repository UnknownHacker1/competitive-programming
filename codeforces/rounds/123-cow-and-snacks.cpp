/*
 * Cow and Snacks  [1209D]
 * Problem:  https://codeforces.com/problemset/problem/1209/D
 * Verdict:  ACCEPTED        Solved: 2021-12-21
 * Language: C++20 (GCC 11-64)
 * Runtime:  62 ms     Memory: 6900 KB
 * Tags:     dfs and similar, dsu, graphs
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1209/submission/140170329
 */

/// isA AC
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
#define tc         \
    int tttttt,subtask;    \
    cin >> tttttt /*>> subtask*/; \
    while (tttttt--)
#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end() 
vector<int>adj[(int)1e5+3];
bool vis[(int)1e5+3];
void dfs(int node){
    if(vis[node])return;
    vis[node]=1;
    for(int child:adj[node]){
        dfs(child);
    }
}
int main()
{
    ACPLS();
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int cnt=0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
            cnt++;
        }
    }
    cout<<m-(n-cnt);
}