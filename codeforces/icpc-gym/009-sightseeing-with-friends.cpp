/*
 * Sightseeing with Friends  [103256D]
 * Problem:  Gym/ICPC contest 103256 - problem D
 * Verdict:  ACCEPTED        Solved: 2021-10-28
 * Language: C++17 (GCC 7-32)
 * Runtime:  1419 ms     Memory: 12800 KB
 * Tags:     n/a
 * Author:   BidoTeima
 * Source:   https://codeforces.com/gym/103256/submission/133379658
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
ll gcd(ll a, ll b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}
ll lcm(ll a, ll b){
    return a/gcd(a,b)*b;
}
ll f(ll x, ll y, ll z){
    return (x/z)-((y-1)/z);
}
int main()
{
    ACPLS();
    int n,m,q;
    cin>>n>>m>>q;
    pair<int,int>a[m];
    for(auto&i:a)cin>>i.first>>i.second;
    sort(a,a+m);
    int pref[m+1]={a[0].second};
    for(int i = 1; i < m; i++){
        pref[i]=max(pref[i-1],a[i].second);
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        if(v<u)
            swap(u,v);
        int idx=upper_bound(a,a+m,make_pair(u,(int)1e9))-a;
        if(idx==m||a[idx].first>u)
            --idx;
        if(idx==-1||pref[idx]<v)
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }
}
