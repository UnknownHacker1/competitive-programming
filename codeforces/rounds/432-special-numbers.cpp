/*
 * Special Numbers  [1594B]
 * Problem:  https://codeforces.com/problemset/problem/1594/B
 * Verdict:  ACCEPTED        Solved: 2021-10-08
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 3600 KB
 * Tags:     bitmasks, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1594/submission/131191315
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
ll POW(ll a, ll b){
    if(b==0)
        return 1;
    if(b&1)
        return (POW(a,b/2)%mod*POW(a,b/2)%mod*a%mod)%mod;
    return (POW(a,b/2)%mod*POW(a,b/2)%mod)%mod;
}
int main()
{
    ACPLS();
tc{
    ll n,k;
    cin>>n>>k;
    ll ans=0,cur=1;
    while(k){
        ans+=(k%2)*cur;
        ans%=mod;
        cur*=n;
        cur%=mod;
        k/=2;
    }
    cout<<ans<<'\n';
}
}
