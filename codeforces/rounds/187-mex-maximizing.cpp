/*
 * MEX maximizing  [1294D]
 * Problem:  https://codeforces.com/problemset/problem/1294/D
 * Verdict:  ACCEPTED        Solved: 2021-10-07
 * Language: C++17 (GCC 7-32)
 * Runtime:  280 ms     Memory: 18000 KB
 * Tags:     data structures, greedy, implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1294/submission/131100367
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
set<int>::iterator back(set<int>&st)
{
    return prev(st.end());
}
int main()
{
    ACPLS();
    int q,x;
    cin>>q>>x;
    multiset<int>st;
    for(int i = 0; i <= q+1; i++)
        st.insert(i);
    int freq[x]={0};
    while(q--){
        int y;
        cin>>y;
        ++freq[y%x];
        while(freq[(*st.begin())%x]>0){
            --freq[(*st.begin())%x];
            st.erase(st.begin());
        }
        cout<<*st.begin()<<'\n';
    }
}
