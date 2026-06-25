/*
 * Boboniu and Bit Operations  [1395C]
 * Problem:  https://codeforces.com/problemset/problem/1395/C
 * Verdict:  ACCEPTED        Solved: 2021-10-06
 * Language: C++17 (GCC 7-32)
 * Runtime:  46 ms     Memory: 4100 KB
 * Tags:     bitmasks, brute force, dp, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1395/submission/130994384
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename _Ty>
using ordered_set = tree<_Ty,null_type,less<_Ty>,rb_tree_tag,tree_order_statistics_node_update>;
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
int a[205],b[205];
int n,m;
int dp[205][512];
int rec(int idx, int cur){
    if(idx==n)
        return cur;
    if(dp[idx][cur]!=-1)
        return dp[idx][cur];
    int ret=1e9;
    for(int i = 0; i < m; i++){
        ret=min(ret,rec(idx+1,cur|(a[idx]&b[i])));
    }
    return dp[idx][cur]=ret;
}
int main()
{
    ACPLS();
    memset(dp,-1,sizeof(dp)); 
    cin>>n>>m;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    for(int i = 0; i < m; i++)
        cin>>b[i];
    cout<<rec(0,0);
}