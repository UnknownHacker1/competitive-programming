/*
 * Getting Zero  [1661B]
 * Problem:  https://codeforces.com/problemset/problem/1661/B
 * Verdict:  ACCEPTED        Solved: 2024-03-05
 * Language: C++20 (GCC 11-64)
 * Runtime:  31 ms     Memory: 2600 KB
 * Tags:     bitmasks, brute force, dfs and similar, dp, graphs, greedy, shortest paths
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1661/submission/249731406
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;     
const int N = 32768;
int dp[N][20];
int rec(int x, int cnt){
    if(!x) return 0;
    if(cnt>=20) return 20;
    if(dp[x][cnt] != -1) return dp[x][cnt];
    return dp[x][cnt] = min(rec((x + 1) % N, cnt + 1), rec((2 * x) % N, cnt + 1)) + 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);   
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        cout<<rec(x, 0)<<' ';
    }
    return 0;
}