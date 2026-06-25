/*
 * Noise Level  [847I]
 * Problem:  https://codeforces.com/problemset/problem/847/I
 * Verdict:  ACCEPTED        Solved: 2023-08-09
 * Language: C++17 (GCC 7-32)
 * Runtime:  1107 ms     Memory: 600 KB
 * Tags:     dfs and similar, implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/847/submission/218021846
 */

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
char grid[253][253];
int sum[253][253],vis[253][253],id=1;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n,m,q,p;
bool check(int x, int y){
    return x>=0&&x<n&&y>=0&&y<m&&grid[x][y]!='*'&&vis[x][y]!=id;
}
void bfs(int sx, int sy, char ch){
    int val=(ch-'A'+1)*q;
    queue<array<int,3>>q;
    q.push({sx,sy,val});
    vis[sx][sy]=id;
    while(!q.empty()){
        int x=q.front()[0];
        int y=q.front()[1];
        int val=q.front()[2];
        q.pop();

        if(val==0)continue;

        sum[x][y]+=val;
        for(int i = 0; i < 4; i++){
            if(check(x+dx[i],y+dy[i])){
                vis[x+dx[i]][y+dy[i]]=id;
                q.push({x+dx[i],y+dy[i],val/2});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>q>>p;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>grid[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j]!='.'&&grid[i][j]!='*'){
                bfs(i,j,grid[i][j]);
                ++id;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(sum[i][j]>p)ans++;
        }
    }
    cout<<ans;
    return 0;
}