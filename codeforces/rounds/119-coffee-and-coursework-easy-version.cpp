/*
 * Coffee and Coursework (Easy version)  [1118D1]
 * Problem:  https://codeforces.com/problemset/problem/1118/D1
 * Verdict:  ACCEPTED        Solved: 2022-01-13
 * Language: C++20 (GCC 11-64)
 * Runtime:  171 ms     Memory: 215900 KB
 * Tags:     brute force, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1118/submission/142646456
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
int n;
int a[105];
short dp[105][105][10005];
short rec(short idx, short k, int m){
    if(m<=0)return 0;
    if(idx==n){
        return 105;
    }
    if(dp[idx][k][m]!=-1)
        return dp[idx][k][m];
    return dp[idx][k][m]=min(
        rec(idx+1,k+1,m-max(0,a[idx]-k)),
        short(rec(idx+1,1,m-a[idx])+1)
        );
}
int main()
{
    ACPLS();  
    memset(dp,-1,sizeof(dp));
    int m;
    cin>>n>>m;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    sort(a,a+n);reverse(a,a+n);
    if(rec(0,0,m)>100)
        cout<<-1;
    else cout<<rec(0,0,m)+1;
}
 
