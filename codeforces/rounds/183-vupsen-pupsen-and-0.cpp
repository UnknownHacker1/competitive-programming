/*
 * Vupsen, Pupsen and 0  [1582D]
 * Problem:  https://codeforces.com/problemset/problem/1582/D
 * Verdict:  ACCEPTED        Solved: 2021-10-28
 * Language: C++17 (GCC 7-32)
 * Runtime:  92 ms     Memory: 1400 KB
 * Tags:     constructive algorithms, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1582/submission/133397990
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
    cin>>n;
    int a[n];
    for(auto&i:a)cin>>i;
    int start=0;
    if(n&1){
        if(a[0]+a[1]!=0){
            cout<<a[2]<<' '<<a[2]<<' '<<-(a[0]+a[1])<<' ';
        }
        else if(a[1]+a[2]!=0){
            cout<<-(a[1]+a[2])<<' '<<a[0]<<' '<<a[0]<<' ';
        }
        else cout<<a[1]<<' '<<-(a[0]+a[2])<<' '<<a[1]<<' ';
        start=3;
    }
    for(int i = start; i+1 < n; i+=2){
        cout<<a[i+1]<<' '<<-a[i]<<' ';
    }
    cout<<'\n';
}
}
