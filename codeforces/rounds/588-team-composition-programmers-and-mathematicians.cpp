/*
 * Team Composition: Programmers and Mathematicians  [1611B]
 * Problem:  https://codeforces.com/problemset/problem/1611/B
 * Verdict:  ACCEPTED        Solved: 2021-11-25
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     binary search, constructive algorithms, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1611/submission/136891924
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
ll f(int a, int b){
    return max({min(a/3,b),min(a/2,b/2),min(a,b/3)});
}
int main()
{
    ACPLS(); 
tc{
    ll a,b;
    cin>>a>>b; 
    cout<<min((a+b)/4,min(a,b))<<'\n';
}
}