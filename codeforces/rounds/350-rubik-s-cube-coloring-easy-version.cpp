/*
 * Rubik's Cube Coloring (easy version)  [1594E1]
 * Problem:  https://codeforces.com/problemset/problem/1594/E1
 * Verdict:  ACCEPTED        Solved: 2021-10-08
 * Language: C++17 (GCC 7-32)
 * Runtime:  30 ms     Memory: 3700 KB
 * Tags:     combinatorics, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1594/submission/131222455
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
ll mod = 1e9+7;
int64_t POW(int64_t a, int64_t b)
{
    if(b==0) return 1;
    a%=mod;
    int64_t res = POW(a,b/2);
    if(b&1)
        return (res%mod*res%mod*a%mod)%mod;
    return (res%mod*res%mod)%mod;
}

int main()
{
    ACPLS();
    ll k;
    cin>>k;
    ll x = 1;
    for(int i = 0; i < k; i++)
        x*=2;
    x-=2;
    cout<<(POW(4,x)*6)%mod;
}
