/*
 * Product 1 Modulo N  [1514C]
 * Problem:  https://codeforces.com/problemset/problem/1514/C
 * Verdict:  ACCEPTED        Solved: 2021-11-17
 * Language: C++20 (GCC 11-64)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     greedy, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1514/submission/136000393
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
    ll n;
    cin>>n;
    ll res = 1, cnt = 0;
    for(ll i = 1; i < n; i++){
        if(__gcd(n,i)==1){
            res*=i;
            res%=n;
            ++cnt;
        }
    }
    cout<<cnt-(res!=1)<<'\n';
    for(ll i = 1; i <= n; i++){
        if(__gcd(n,i)==1&&(i!=res||res==1))
            cout<<i<<' ';
    }
}