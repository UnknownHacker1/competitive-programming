/*
 * Concatenated Multiples  [1029D]
 * Problem:  https://codeforces.com/problemset/problem/1029/D
 * Verdict:  ACCEPTED        Solved: 2021-11-17
 * Language: C++20 (GCC 11-64)
 * Runtime:  1980 ms     Memory: 104300 KB
 * Tags:     implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1029/submission/136012689
 */

/// isA AC
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
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
int f(int x){
    int ret=0;
    while(x){
        ret++;
        x/=10;
    }
    return ret;
}
map<int,int>freq[11];
int main()
{
    ACPLS();
    int n;
    int k;
    cin>>n>>k;
    int a[n];
    for(auto&i:a)cin>>i;
    ll ans=0;
    for(int i = 0; i < n; i++){
        ++freq[f(a[i])][a[i]%k];
    }
    for(int i = 0; i < n; i++){
        --freq[f(a[i])][a[i]%k];
        ll res=a[i];
        for(int cnt = 1; cnt < 11; cnt++){
            res=(res*10)%k;
            ans+=freq[cnt][(k-res==k)?0:k-res];
        }
        ++freq[f(a[i])][a[i]%k];
    }
    cout<<ans;
}
