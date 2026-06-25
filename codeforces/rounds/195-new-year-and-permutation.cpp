/*
 * New Year and Permutation  [1284C]
 * Problem:  https://codeforces.com/problemset/problem/1284/C
 * Verdict:  ACCEPTED        Solved: 2021-11-10
 * Language: C++17 (GCC 7-32)
 * Runtime:  46 ms     Memory: 3400 KB
 * Tags:     combinatorics, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1284/submission/134921309
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
ll n,mod;
ll fact[(int)3e5+5];
int main()
{
    ACPLS();
    cin>>n>>mod;
    fact[0]=1; 
    for(int i = 1; i <= n; i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    ll ans=0;
    for(int i = 1; i <= n; i++){
        ans+=((n-i+1)%mod*fact[i]%mod*fact[n-i+1]%mod);
        ans%=mod;
    }
    cout<<ans;
}
