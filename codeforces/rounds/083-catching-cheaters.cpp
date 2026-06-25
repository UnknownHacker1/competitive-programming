/*
 * Catching Cheaters  [1446B]
 * Problem:  https://codeforces.com/problemset/problem/1446/B
 * Verdict:  ACCEPTED        Solved: 2025-10-25
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  796 ms     Memory: 98100 KB
 * Tags:     dp, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1446/submission/345675024
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;    
const int N = 5005;

int dp[N][N],n,m;

string a, b;

int rec(int i, int j){
    if(i == n || j == m) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ret = 0;

    if(a[i] == b[j]){
        ret = max(ret, 2 + rec(i + 1, j + 1));
    }
    ret = max(ret, max(rec(i + 1, j), rec(i, j + 1)) - 1);

    return dp[i][j] = ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);   

    memset(dp, -1, sizeof(dp));

    cin >> n >> m >> a >> b;

    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans = max(ans, rec(i, j));
        }
    }
    cout << ans;

    return 0;
}
