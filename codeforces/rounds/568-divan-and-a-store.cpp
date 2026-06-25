/*
 * Divan and a Store  [1614A]
 * Problem:  https://codeforces.com/problemset/problem/1614/A
 * Verdict:  ACCEPTED        Solved: 2021-11-26
 * Language: C++20 (GCC 11-64)
 * Runtime:  0 ms     Memory: 0 KB
 * Tags:     brute force, constructive algorithms, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1614/submission/136991367
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
    ll n,l,r,k;
    cin>>n>>l>>r>>k;
    ll a[n];
    for(auto&i:a)cin>>i;
    sort(a,a+n);
    int ans=0;
    for(int i = 0; i < n; i++){
        if(a[i]<l)
            continue;
        if(a[i]>r)
            break;
        if(k>=a[i]){
            k-=a[i];
            ++ans;
        }
    }
    cout<<ans<<'\n';
}
}