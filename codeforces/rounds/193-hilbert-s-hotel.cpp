/*
 * Hilbert's Hotel  [1345C]
 * Problem:  https://codeforces.com/problemset/problem/1345/C
 * Verdict:  ACCEPTED        Solved: 2021-10-21
 * Language: C++17 (GCC 7-32)
 * Runtime:  139 ms     Memory: 6700 KB
 * Tags:     math, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1345/submission/132645135
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
    ll n;
    cin>>n;
    ll a[n];
    for(auto&i:a)cin>>i;
    map<int,int>freq{};
    for(int i = 0; i < n; i++){
        ++freq[(i+a[i%n]+n*(ll)1e9)%n];
    }
    bool ans=1;
    for(auto it:freq){
        if(it.second>1)ans=0;
    }
    cout<<(ans?"YES\n":"NO\n");
}   
}