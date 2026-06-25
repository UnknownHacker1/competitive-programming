/*
 * Cutting Out  [1077D]
 * Problem:  https://codeforces.com/problemset/problem/1077/D
 * Verdict:  ACCEPTED        Solved: 2021-09-26
 * Language: C++17 (GCC 7-32)
 * Runtime:  124 ms     Memory: 9400 KB
 * Tags:     binary search, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1077/submission/129917505
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
ll mod=998244353;
int main()
{
    ACPLS();
    int n,k;
    cin>>n>>k;
    int freq[(int)2e5+3]={0};
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        freq[x]++;
    }
    set<pair<int,int>>st;
    for(int i = 1; i <= 2e5; i++){
        if(freq[i]>0){
            st.insert({freq[i],i});
        }
    }
    int curf[(int)2e5+3]={0};
    while(k>0){
        cout<<prev(st.end())->second<<' ';
        ++curf[prev(st.end())->second];
        auto it=*prev(st.end());
        st.erase(prev(st.end()));
        if(curf[it.second]+1<=freq[it.second])
            st.insert({freq[it.second]/(curf[it.second]+1),it.second});
        --k;
    }
}