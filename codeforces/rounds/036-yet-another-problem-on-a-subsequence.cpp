/*
 * Yet Another Problem On a Subsequence  [1000D]
 * Problem:  https://codeforces.com/problemset/problem/1000/D
 * Verdict:  ACCEPTED        Solved: 2022-01-17
 * Language: C++20 (GCC 11-64)
 * Runtime:  31 ms     Memory: 4100 KB
 * Tags:     combinatorics, dp
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1000/submission/143165505
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
ll mod = 998244353;
int n;
int a[(int)1e3+5];
int dp[(int)1e3+5][(int)1e3+5];
int rec(int idx, int k){
    if(idx==n){
        if(k==0)return 1;
        return 0;
    }
    if(dp[idx][k]!=-1)
        return dp[idx][k];
    ll op1=0,op2=0,op3=0;
    op1=rec(idx+1, k);
    if(a[idx]<=n&&a[idx]>0&&k==0)op2=rec(idx+1,a[idx]);
    if(k>0)op3=rec(idx+1,k-1);
    return dp[idx][k]=(op1+op2+op3)%mod;
}
int main()
{
    ACPLS();
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    cout<<rec(0,0)-1;
}

