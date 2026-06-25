/*
 * Petya and Array  [1042D]
 * Problem:  https://codeforces.com/problemset/problem/1042/D
 * Verdict:  ACCEPTED        Solved: 2022-07-05
 * Language: C++20 (GCC 11-64)
 * Runtime:  139 ms     Memory: 14200 KB
 * Tags:     data structures, divide and conquer, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1042/submission/162921315
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename _Type, typename _Cmp = less<_Type>>
using ordered_set = tree<_Type, null_type, _Cmp, rb_tree_tag,tree_order_statistics_node_update>;
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
void moo(string fileName){
    freopen((fileName+".in").c_str(),"r",stdin);
    freopen((fileName+".out").c_str(),"w",stdout);
}
#define tc int tttt;cin>>tttt;while(tttt--)
int main()
{
    ACPLS();    
    int n;
    ll t;
    cin>>n>>t;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
        if(i)a[i]+=a[i-1];
    }
    ordered_set<pair<ll,int>>s;
    s.insert({0,-1});
    ll ans=0;
    for(int i = 0; i < n; i++){
        ans+=s.order_of_key(make_pair(t-a[i],-1));
        s.insert({-a[i],i});
    }
    cout<<ans;
}