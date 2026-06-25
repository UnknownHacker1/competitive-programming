/*
 * Good Subarrays  [1398C]
 * Problem:  https://codeforces.com/problemset/problem/1398/C
 * Verdict:  ACCEPTED        Solved: 2021-11-07
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 4700 KB
 * Tags:     data structures, dp, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1398/submission/134600964
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
    map<int,int>freq{};
    freq[0]=1;
    ll ans=0;
    for(int i = 0; i < n; i++){
        char ch;
        cin>>ch;
        a[i]=ch-'0';
        if(i)a[i]+=a[i-1];
        ++freq[a[i]-i-1];
        ans+=freq[a[i]-i-1]-1;
    }
    cout<<ans<<'\n';
}
}
