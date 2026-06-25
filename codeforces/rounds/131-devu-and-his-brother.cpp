/*
 * Devu and his Brother  [439D]
 * Problem:  https://codeforces.com/problemset/problem/439/D
 * Verdict:  ACCEPTED        Solved: 2023-06-03
 * Language: C++20 (GCC 11-64)
 * Runtime:  61 ms     Memory: 1600 KB
 * Tags:     binary search, sortings, ternary search, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/439/submission/208347079
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 3;
int n,m;
int a[N],b[N];
ll f(int x){
    ll ret = 0;
    for(int i = 0; i < n; i++)ret += max(0, x - a[i]);
    for(int i = 0; i < m; i++)ret += max(0, b[i]  - x);
    return ret;
}
int main()
{ 
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);     
    cin>>n>>m;
    for(int i = 0; i < n; ++i)cin>>a[i]; 
    for(int i = 0; i < m; ++i)cin>>b[i];
    int l = 0, r = 1e9;
    ll ans = 1e18;
    while(l <= r){
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if(f(mid1) >= f(mid2)){
            l = mid1 + 1;
            ans=min(ans,f(mid2));
        }else r = mid2 - 1, ans = min(ans,f(mid1));
    }
    cout<<ans;
    return 0;
}