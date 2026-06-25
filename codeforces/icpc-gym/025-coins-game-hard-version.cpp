/*
 * Coins Game (hard version)  [103256E2]
 * Problem:  Gym/ICPC contest 103256 - problem E2
 * Verdict:  ACCEPTED        Solved: 2021-10-28
 * Language: C++17 (GCC 7-32)
 * Runtime:  15 ms     Memory: 1000 KB
 * Tags:     n/a
 * Author:   BidoTeima
 * Source:   https://codeforces.com/gym/103256/submission/133381570
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
    ll x = n*(n+1)/2;
    ll y = 2;
    if(x%2==0)
        cout<<x/2<<'/'<<1;
    else
        cout<<x<<'/'<<2;

}
