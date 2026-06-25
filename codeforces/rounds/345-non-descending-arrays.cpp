/*
 * Non-Descending Arrays  [2144C]
 * Problem:  https://codeforces.com/problemset/problem/2144/C
 * Verdict:  ACCEPTED        Solved: 2025-10-17
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  281 ms     Memory: 4500 KB
 * Tags:     combinatorics, dp, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2144/submission/344106422
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;  

const int N = 105, mod = 998244353;
int dp[N][N][N],n,a[N],b[N];
int rec(int idx, int prvI, int prvE){
    if(idx == n){
        return 1;
    }
    if(dp[idx][prvI + 1][prvE + 1] != -1)
        return dp[idx][prvI + 1][prvE + 1];
    int ret = 0;
    // if we incl idx, then
    // (prvI == -1 || a[idx] >= a[prvI]) (1i)
    // (prvI == -1 || b[idx] >= b[prvI]) (1ii)
    // (prvE == -1 || a[idx] >= b[prvE]) (2i)
    // (prvE == -1 || b[idx] >= a[prvE]) (2ii)
    if((prvI == -1 || a[idx] >= a[prvI]) && (prvI == -1 || b[idx] >= b[prvI]) && 
        (prvE == -1 || a[idx] >= b[prvE]) && (prvE == -1 || b[idx] >= a[prvE])){
            ret += rec(idx + 1, idx, prvE);
        }
    // if we don't, then
    // (prvE == -1 || a[idx] >= a[prvE]) (1i)
    // (prvE == -1 || b[idx] >= b[prvE]) (1ii)
    // (prvI == -1 || a[idx] >= b[prvI]) (2i)
    // (prvI == -1 || b[idx] >= a[prvI]) (2ii)
    if((prvE == -1 || a[idx] >= a[prvE]) && (prvE == -1 || b[idx] >= b[prvE]) &&
        (prvI == -1 || a[idx] >= b[prvI]) && (prvI == -1 || b[idx] >= a[prvI])){
            ret += rec(idx + 1, prvI, idx);
        }
    if(ret >= mod) ret -= mod;

    return dp[idx][prvI + 1][prvE + 1] = ret;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);  
    int t;
    cin>>t;
    while(t--){ 
        cin>>n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> b[i];

        memset(dp, -1, sizeof(dp));

        cout << rec(0, -1, -1) % mod << '\n';
    }
    return 0;
}