/*
 * Save More Mice  [1593C]
 * Problem:  https://codeforces.com/problemset/problem/1593/C
 * Verdict:  ACCEPTED        Solved: 2021-10-13
 * Language: C++17 (GCC 7-32)
 * Runtime:  171 ms     Memory: 3100 KB
 * Tags:     binary search, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1593/submission/131785020
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
    ll n,k;
    cin>>n>>k;
    ll a[k];
    for(auto&i:a)cin>>i;
    sort(a,a+k),reverse(a,a+k);
    int lo = 1, hi = k, ans = 0;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        ll sum=0;
        for(int i = 0; i < mid; i++){
            sum+=n-a[i];
        }
        if(sum<n){
            ans=mid;
            lo=mid+1;
        } else hi=mid-1;
    }
    cout<<ans<<'\n';
}
}