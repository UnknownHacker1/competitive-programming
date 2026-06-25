/*
 * Arrow Path  [1948C]
 * Problem:  https://codeforces.com/problemset/problem/1948/C
 * Verdict:  ACCEPTED        Solved: 2025-03-23
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  62 ms     Memory: 10100 KB
 * Tags:     brute force, constructive algorithms, dfs and similar, dp, graphs, shortest paths
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1948/submission/312064723
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
const int N = 2e5 + 3;
bool vis[N][2][2];
char s[N][2];
int n;
void dfs(int i, bool g, bool a){
    if(vis[i][g][a])return;
    vis[i][g][a]=1;
    if(!a){
        //l,r,u,d
        if(i>=2)dfs(i - 1, g, 1);
        if(i<=n-1)dfs(i + 1, g, 1);
        dfs(i, !g, 1);
    }else{
        if(s[i][g]=='<')dfs(i-1,g,0);
        else dfs(i + 1, g, 0);     
    }
}
int main()
{ 
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);  
    int t;
    cin>>t;
    while(t--){ 
        cin>>n;
        for(int j = 0; j < 2; j++) for(int i = 1; i <= n; i++){
            cin>>s[i][j];
            vis[i][j][0]=vis[i][j][1]=0;
        }
        dfs(1,0,0);
        cout<<(vis[n][1][0]||vis[n][1][1] ? "YES\n":"NO\n");
    }
    return 0;
}