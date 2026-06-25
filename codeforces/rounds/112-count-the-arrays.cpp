/*
 * Count the Arrays  [1312D]
 * Problem:  https://codeforces.com/problemset/problem/1312/D
 * Verdict:  ACCEPTED        Solved: 2021-11-20
 * Language: C++20 (GCC 11-64)
 * Runtime:  124 ms     Memory: 0 KB
 * Tags:     combinatorics, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1312/submission/136231966
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
ll mod = 998244353;
ll POW(ll a, ll b){
    if(b==0)
        return 1;
    ll x = POW(a,b/2);
    if(b&1)
        return (x%mod*x%mod*a%mod)%mod;
    return (x%mod*x%mod)%mod;
}
ll inv(ll a){
    return POW(a,mod-2);
}
ll ncr(int n,int r){
    ll ans=1;
    for(ll i = 0; i < min(r,n-r); i++){
        ans*=(n-i);
        ans%=mod;
        ans*=inv(i+1);
        ans%=mod;
    }
    return ans;
}
int main()
{
    ACPLS();
    ll n,m;
    cin>>n>>m;
    if(n>2){
        cout<<(ncr(m,n-1)%mod*(n-2)%mod*POW(2,n-3)%mod)%mod;
    }
    else cout<<0;
}