/*
 * Divan and bitwise operations  [1614C]
 * Problem:  https://codeforces.com/problemset/problem/1614/C
 * Verdict:  ACCEPTED        Solved: 2021-11-26
 * Language: C++20 (GCC 11-64)
 * Runtime:  93 ms     Memory: 0 KB
 * Tags:     bitmasks, combinatorics, constructive algorithms, dp, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1614/submission/137018468
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
ll mod = (ll)1e9+7;
ll POW(ll a, ll b){
    if(b==0)
        return 1;
    ll x = POW(a,b/2);
    if(b&1)
        return (x%mod*x%mod*a%mod)%mod;
    return (x%mod*x%mod)%mod;
}
int main()
{
    ACPLS(); 
tc{
    int n,m;
    cin>>n>>m;
    ll ans=0;
    for(int i = 0; i < m; i++){
        ll l,r,x;
        cin>>l>>r>>x;
        ans|=x;
    }
    cout<<(ans%mod*POW(2,n-1)%mod)%mod<<'\n';
}
}