/*
 * Divide and Summarize  [1461D]
 * Problem:  https://codeforces.com/problemset/problem/1461/D
 * Verdict:  ACCEPTED        Solved: 2021-11-07
 * Language: C++17 (GCC 7-32)
 * Runtime:  155 ms     Memory: 12100 KB
 * Tags:     binary search, brute force, data structures, divide and conquer, implementation, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1461/submission/134599480
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
ll a[(int)1e5+3];
ll pre[(int)1e5+3];
map<ll,bool>freq{};
void rec(int l, int r){
    if(l>r)
        return;
    freq[sumrange(l,r,pre)]=1;
    if(a[l]==a[r])
        return;
    int mid = upper_bound(a+l,a+r+1,(a[l]+a[r])/2)-a-1;
    rec(l,mid);
    rec(mid+1,r);
}
int main()
{
    ACPLS();
tc{
    freq.clear();
    int n,q;
    cin>>n>>q;
    for(int i = 0; i < n; i++)cin>>a[i];
    sort(a,a+n);
    pre[0]=a[0];
    for(int i = 1; i < n; i++)
        pre[i]=pre[i-1]+a[i];
    rec(0,n-1);
    while(q--){
        ll s;
        cin>>s;
        if(freq[s])
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}
}
