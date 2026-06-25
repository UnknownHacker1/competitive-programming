/*
 * IOI '09 P4 - Raisins  [ioi09p4]
 * Problem:  https://dmoj.ca/problem/ioi09p4
 * Verdict:  ACCEPTED (10.0 pts)   Solved: 2023-08-25
 * Language: C++20
 * Runtime:  1.683565117 s     Memory: 65192.0 KB
 * Source:   https://dmoj.ca/src/5731916
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
const int N = 53;
ll pref[N][N];
ll dp[N][N][N][N];
ll get_sum(int i, int j, int x, int y){
    return pref[x][y] - pref[x][j - 1] - pref[i - 1][y] + pref[i - 1][j - 1];
}
ll rec(int i, int j, int x, int y){
    if(i == x && j == y)
        return 0;
    if(dp[i][j][x][y] != -1){
        return dp[i][j][x][y];
    }
    ll ret = 1e18;
    ll sm = get_sum(i, j, x, y); 
    for(int c = i; c < x; c++){
        ret = min(ret, rec(i, j, c, y) + rec(c+1, j, x, y) + sm);
    } 
    for(int c = j; c < y; c++){
        ret = min(ret, rec(i, j, x, c) + rec(i, c+1, x, y) + sm);
    }
    return dp[i][j][x][y]=ret;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>pref[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            pref[i][j] += pref[i][j - 1];
        }
    }
    for(int j = 1; j <= m; j++){
        for(int i = 1; i <= n; i++){
            pref[i][j] += pref[i - 1][j];
        }
    } 
    cout<<rec(1,1,n,m);
    return 0;
}