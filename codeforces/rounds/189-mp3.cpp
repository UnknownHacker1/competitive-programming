/*
 * MP3  [1199C]
 * Problem:  https://codeforces.com/problemset/problem/1199/C
 * Verdict:  ACCEPTED        Solved: 2021-10-16
 * Language: C++17 (GCC 7-32)
 * Runtime:  358 ms     Memory: 17900 KB
 * Tags:     two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1199/submission/132118020
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
    int n,I;
    cin>>n>>I;
    int a[n];
    map<int,int>freq{};
    for(auto&i:a)cin>>i,++freq[i];
    int k = (1<<(min(8*I/n,30)));
    int ans=0,cur=0;
    vector<int>vc;
    for(auto&i:freq){
        cur+=i.second;
        if((int)vc.size()>=k)
            cur-=vc[(int)vc.size()-k];
        vc.push_back(i.second);
        ans=max(ans,cur);
    }
    cout<<n-ans;
}