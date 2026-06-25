/*
 * Divan and a New Project   [1614B]
 * Problem:  https://codeforces.com/problemset/problem/1614/B
 * Verdict:  ACCEPTED        Solved: 2021-11-26
 * Language: C++20 (GCC 11-64)
 * Runtime:  62 ms     Memory: 6300 KB
 * Tags:     constructive algorithms, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1614/submission/137007814
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
    ll n;
    cin>>n;
    ll a[n];
    pair<ll,ll>b[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
        b[i].first=a[i];
        b[i].second=i;
    }
    sort(b,b+n);
    map<int,int>mp{};
    int x = 1;
    ll arr[n];
    for(int i = n-1; i >= 0; i--){
        arr[b[i].second]=x;
        if(x>0){
            x=-x;
        }
        else{
            x=abs(x)+1;
        }
    }
    ll ans=0;
    for(int i = 0; i < n; i++){
        ans+=2*abs(arr[i])*a[i];
    }
    cout<<ans<<'\n';
    cout<<"0 ";
    for(ll i:arr)
        cout<<i<<' ';
    cout<<'\n';
}
}