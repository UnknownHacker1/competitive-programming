/*
 * Sasha and a Bit of Relax  [1109A]
 * Problem:  https://codeforces.com/problemset/problem/1109/A
 * Verdict:  ACCEPTED        Solved: 2021-10-11
 * Language: C++17 (GCC 7-32)
 * Runtime:  249 ms     Memory: 13700 KB
 * Tags:     dp, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1109/submission/131556099
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
    int n;
    cin>>n;
    int a[n];
    for(auto&i:a)cin>>i;
    map<int,int>freq[2];
    freq[1][0]=1;
    ll ans=0,cur=0;
    for(int i = 0; i < n; i++){
        cur^=a[i];
        ans+=freq[i%2][cur];
        ++freq[i%2][cur];
    }
    cout<<ans;
}