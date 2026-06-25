/*
 * Pair of Topics  [1324D]
 * Problem:  https://codeforces.com/problemset/problem/1324/D
 * Verdict:  ACCEPTED        Solved: 2021-05-09
 * Language: C++17 (GCC 7-32)
 * Runtime:  170 ms     Memory: 8300 KB
 * Tags:     binary search, data structures, sortings, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1324/submission/115803521
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
int main() {
    fast
    int n;
    cin>>n;
    ll a[n],b[n],diff[n];
    for(auto&i:a)cin>>i;
    for(auto&i:b)cin>>i;
    for(int i = 0; i < n; i++) {
        diff[i]=a[i]-b[i];
    }
    sort(diff,diff+n);
    ll ans=0;
    for(int i = 0; i < n; i++) {
        bool f=diff[i]>0;
        int idx=lower_bound(diff,diff+n,0-diff[i]+1)-diff+1;
        if(idx>n)continue;
        ans+=n-idx+1-f;
    }
    cout<<ans/2<<'\n';
}