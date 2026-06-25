/*
 * Elections  [1593A]
 * Problem:  https://codeforces.com/problemset/problem/1593/A
 * Verdict:  ACCEPTED        Solved: 2021-10-13
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 0 KB
 * Tags:     math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1593/submission/131751048
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
    ll a,b,c;
    cin>>a>>b>>c;
    cout<<max(0ll,max(b,c)-a+1)<<' ';
    cout<<max(0ll,max(a,c)-b+1)<<' ';
    cout<<max(0ll,max(a,b)-c+1)<<' ';
    cout<<'\n';
}
}