/*
 * Delete Two Elements  [1598C]
 * Problem:  https://codeforces.com/problemset/problem/1598/C
 * Verdict:  ACCEPTED        Solved: 2021-10-10
 * Language: C++17 (GCC 7-32)
 * Runtime:  295 ms     Memory: 21100 KB
 * Tags:     data structures, dp, implementation, math, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1598/submission/131473110
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
int main()
{
    ACPLS(); 
tc{
    ll n,k=0;
    cin>>n;
    ll a[n];
    for(auto&i:a)cin>>i,k+=i;
    if(2*k%n!=0){
        cout<<"0\n";
        continue;
    }
    k=2*k/n;
    ll ans=0;
    map<ll,ll>freq{};
    for(ll i:a){
        ans+=freq[k-i];
        ++freq[i];
    }
    cout<<ans<<'\n';
}
}