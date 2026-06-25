/*
 * Solve The Maze  [1365D]
 * Problem:  https://codeforces.com/problemset/problem/1365/D
 * Verdict:  ACCEPTED        Solved: 2022-01-13
 * Language: C++20 (GCC 11-64)
 * Runtime:  31 ms     Memory: 400 KB
 * Tags:     constructive algorithms, dfs and similar, dsu, graphs, greedy, implementation, shortest paths
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1365/submission/142650663
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
char grid[55][55];
bool vis[55][55];
vector<pair<int,int>>adj[55][55];
int n,m;
bool valid(int i, int j){
    return(1<=i&&i<=n&&1<=j&&j<=m&&grid[i][j]!='#')&&vis[i][j]==0;
}
void dfs(int i, int j){
    vis[i][j]=1;
    for(auto i:adj[i][j])
        if(!vis[i.first][i.second])
            dfs(i.first,i.second);
}
int main()
{
    ACPLS();  
tc{
    memset(vis,0,sizeof(vis));
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            adj[i][j].clear();
        }
    } 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>grid[i][j];
        }
    }
    bool ans=1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(grid[i][j]=='B'){
            if(valid(i-1,j)&&grid[i-1][j]=='.'){
                grid[i-1][j]='#';
            }
            if(valid(i,j-1)&&grid[i][j-1]=='.'){
                grid[i][j-1]='#';
            }
            if(valid(i+1,j)&&grid[i+1][j]=='.'){
                grid[i+1][j]='#';
            }
            if(valid(i,j+1)&&grid[i][j+1]=='.'){
                grid[i][j+1]='#';
            }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(grid[i][j]!='#'){
            if(valid(i-1,j)){adj[i][j].push_back({i-1,j});}
            if(valid(i,j-1)){adj[i][j].push_back({i,j-1});}
            if(valid(i+1,j)){adj[i][j].push_back({i+1,j});}
            if(valid(i,j+1)){adj[i][j].push_back({i,j+1});}
            }
        }
    }
    dfs(n,m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(grid[i][j]=='G'){
                //cout<<i<<' '<<j<<": "<<vis[i][j]<<'\n';
                ans&=vis[i][j];
            }
            if(grid[i][j]=='B')
                ans&=!vis[i][j];
        }
    }
    cout<<(ans?"Yes\n":"No\n");
}
}
 
