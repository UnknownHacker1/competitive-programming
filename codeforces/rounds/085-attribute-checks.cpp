/*
 * Attribute Checks  [2025D]
 * Problem:  https://codeforces.com/problemset/problem/2025/D
 * Verdict:  ACCEPTED        Solved: 2025-03-11
 * Language: C++17 (GCC 7-32)
 * Runtime:  1264 ms     Memory: 306100 KB
 * Tags:     brute force, data structures, dp, implementation, math, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2025/submission/309967211
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;     
const int M = 5005, N = 2e6 + 3;
int dp[M][M], a[N], n, cnt[M][M][2]; // cnt[i][j][0] -> cnt [pos[i]+1,pos[i+1]-1] <= j for intelligence
                                     //    `   ` [1] ->    `    `     `     `     <= j for strength
int m;
vector<int>pos;
int rec(int i, int in){ // intelligence spent 
    if(i == m) return 0;
    if(dp[i][in] != -1) return dp[i][in]; 
    return dp[i][in] = max(rec(i + 1, in + 1)+cnt[i][in+1][0]+cnt[i][i-in][1], 
    rec(i + 1, in)+cnt[i][in][0]+cnt[i][i+1-in][1]);
}
int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(!a[i])pos.push_back(i);
    } 
    pos.push_back(n);
    // precompute >= x in each [pos[i]+1,pos[i+1]-1]
    for(int i = 0; i < m; i++){
        for(int idx = pos[i] + 1; idx < pos[i + 1]; idx++){
            ++cnt[i][abs(a[idx])][a[idx]>0];
        }
        for(int x = 1; x <= m; x++){
            cnt[i][x][0]+=cnt[i][x-1][0];
            cnt[i][x][1]+=cnt[i][x-1][1];
            //cout<<i<<' '<<x<<": "<<cnt[i][x][0]<<'\n';
        }
    }
    cout<<rec(0,0);
    return 0;
}
