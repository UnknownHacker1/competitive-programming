/*
 * NOIP '08 P3 - Message Passing  [noip08p3]
 * Problem:  https://dmoj.ca/problem/noip08p3
 * Verdict:  ACCEPTED (15.0 pts)   Solved: 2023-01-09
 * Language: C++20
 * Runtime:  0.153920474 s     Memory: 32004.0 KB
 * Source:   https://dmoj.ca/src/5201030
 */

/*
ID: BidoTeima
LANG: C++11
TASK:
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void moo(string filename);
void ACPLS(string str = "")
{
    if(str=="NOF")return;
    if(str.size())
        moo(str);
    else{
#ifndef ONLINE_JUDGE
        freopen("output.txt", "w", stdout);
        freopen("input.txt", "r", stdin);
#endif
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void moo(string fileName){
    freopen((fileName+".in").c_str(),"r",stdin);
    freopen((fileName+".out").c_str(),"w",stdout);
}
#define tc         \
    int tttttt/*,subtask*/;    \
    cin >> tttttt/* >> subtask*/; \
    while (tttttt--)/*end
*/    
int n,m;
int a[52][52];
int dx[2]={0,1};
int dy[2]={1,0};
int dp[52][52][52][52];
bool valid(int i, int j, int x, int y){
    if(i > n || j > m || x > n || y > m)
        return 0;
    if(i == x && j == y)
        return 0;
    return 1;
}
int rec(int i, int j, int x, int y){
    if(i == n && j == m){
        return 0;
    }
    if(dp[i][j][x][y]!=-1)
        return dp[i][j][x][y];
    int ret = 0;
    for(int moveX = 0; moveX < 2; moveX++){
        for(int moveY = 0; moveY < 2; moveY++){
            if(!valid(i + dx[moveX], j + dy[moveX],
            x + dx[moveY], y + dy[moveY]))
                continue;
            ret = max(ret, rec(i + dx[moveX], j + dy[moveX],
            x + dx[moveY], y + dy[moveY]));
        }
    }
    return dp[i][j][x][y]=ret+a[i][j]+a[x][y];
}
int main()
{ 
    ACPLS();  
    memset(dp,-1,sizeof(dp));  
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>a[i][j];
        }
    }
    cout<<rec(1, 1, 1, 1);
}