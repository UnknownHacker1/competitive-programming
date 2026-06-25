/*
 * Energy  [104391A]
 * Problem:  Gym/ICPC contest 104391 - problem A
 * Verdict:  ACCEPTED        Solved: 2023-07-11
 * Language: C++20 (GCC 11-64)
 * Runtime:  280 ms     Memory: 7200 KB
 * Tags:     n/a
 * Author:   BidoTeima
 * Source:   https://codeforces.com/gym/104391/submission/213264799
 */

#include <bits/stdc++.h>
using namespace std; 
using ll = int64_t;
const int N = 303, mod = 1e9 + 7;
int n,k,d;
int p[N];
#define sum(l, r) (p[r] - (l == 0? 0 : p[l - 1]))
ll dp[10][N][N];
ll rec(int l, int r, int lvl){
    if(lvl == 0)
        return 1; 
    if(dp[lvl][l][r] != -1)
        return dp[lvl][l][r];
    ll ret = 0;
    for(int i = l; i < r; i++){
        if(abs(sum(l, i) - sum(i + 1, r)) <= d){
            ret += (rec(l, i, lvl - 1) % mod * rec(i + 1, r, lvl - 1)) % mod;
            ret %= mod;
        }
    }
    return dp[lvl][l][r] = ret;   
}
int main()
{ 
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);  
    memset(dp, -1, sizeof(dp));  
    cin>>n>>k>>d;
    for(int i = 0; i < n; i++){
        cin>>p[i];
        if(i)p[i] += p[i - 1];
    }
    cout<<rec(0, n - 1, k - 1);
    return 0;
}