/*
 * Constructing the Array  [1353D]
 * Problem:  https://codeforces.com/problemset/problem/1353/D
 * Verdict:  ACCEPTED        Solved: 2021-10-30
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 5000 KB
 * Tags:     constructive algorithms, data structures, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1353/submission/133586657
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
    int a[n+1]={0};
    vector<pair<int,int>>v;
    v.push_back({1,n});
    for(int i = 0; i < min(n,(int)v.size()); i++){
        int m = (v[i].first+v[i].second)/2;
        if((v[i].second-v[i].first+1)%2==1){
            if(m-1>=v[i].first)v.push_back({v[i].first,m-1});
            if(v[i].second>=m+1)v.push_back({m+1,v[i].second});
        }
        else{
            if(v[i].second>=m+1)v.push_back({m+1,v[i].second});
            if(m-1>=v[i].first)v.push_back({v[i].first,m-1});
        }
    }
    sort(all(v),[](pair<int,int>p1,pair<int,int>p2){
        if(p1.second-p1.first==p2.second-p2.first)
            return p1.first<p2.first;

        else return p1.second-p1.first>p2.second-p2.first;
    });
    for(int i = 0; i < (int)v.size(); i++)
        a[(v[i].first+v[i].second)/2]=i+1;
    for(int i = 1; i <= n; i++)
        cout<<a[i]<<' ';
    cout<<'\n';
}
}
