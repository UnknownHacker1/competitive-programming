/*
 * Gamer Hemose  [1592A]
 * Problem:  https://codeforces.com/problemset/problem/1592/A
 * Verdict:  ACCEPTED        Solved: 2021-10-03
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 3600 KB
 * Tags:     binary search, greedy, math, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1592/submission/130673160
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
    int n;
    ll h;
    cin>>n>>h;
    ll a[n],sum=0;
    for(auto&i:a)cin>>i,sum+=i;
    sort(a,a+n),reverse(a,a+n);
    ll ans=h/(a[0]+a[1]);
    h-=ans*(a[0]+a[1]);
    ans*=2;
    int idx=0;
    while(h>0){
        h-=a[idx];
        ++ans;
        idx^=1;
    }
    cout<<ans<<'\n';
}
}
