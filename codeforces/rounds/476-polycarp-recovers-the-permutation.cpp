/*
 * Polycarp Recovers the Permutation  [1611C]
 * Problem:  https://codeforces.com/problemset/problem/1611/C
 * Verdict:  ACCEPTED        Solved: 2021-11-25
 * Language: C++20 (GCC 11-64)
 * Runtime:  46 ms     Memory: 800 KB
 * Tags:     constructive algorithms
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1611/submission/136906631
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
    int n;
    cin>>n;
    int a[n];
    for(auto&i:a)cin>>i;
    if(a[0]!=n&&a[n-1]!=n){
        cout<<"-1\n";
        continue;
    }
    reverse(a,a+n);
    for(int i:a)
        cout<<i<<' ';
    cout<<'\n';
}
}