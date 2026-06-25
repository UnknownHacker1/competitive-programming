/*
 * Bear and Friendship Condition  [771A]
 * Problem:  https://codeforces.com/problemset/problem/771/A
 * Verdict:  ACCEPTED        Solved: 2022-02-10
 * Language: C++20 (GCC 11-64)
 * Runtime:  78 ms     Memory: 17500 KB
 * Tags:     dfs and similar, dsu, graphs
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/771/submission/145840536
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
vector<int>adj[150005];
vector<int>comp;
bool vis[150005];
void dfs(int node){
    if(vis[node])return;
    vis[node]=1;
    comp.push_back(node);
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
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool ok = 1;
    for(int i = 1; i <= n; i++){
        comp.clear();
        if(!vis[i]){
            dfs(i);
        }
        for(int j = 0; j < (int)comp.size(); j++){
            ok&=(int)adj[comp[j]].size()==(int)comp.size()-1;
        }
    }
    if(ok)cout<<"YES\n";
    else cout<<"NO\n";
}


