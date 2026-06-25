/*
 * CCO '15 P1 - Hungry Fox  [cco15p1]
 * Problem:  https://dmoj.ca/problem/cco15p1
 * Verdict:  ACCEPTED (15.0 pts)   Solved: 2023-06-10
 * Language: C++20
 * Runtime:  0.192904659 s     Memory: 5696.0 KB
 * Source:   https://dmoj.ca/src/5580818
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
ll a[(int)1e5 + 3],n;
ll f(ll w, bool trn){
    vector<ll>b;
    int l = 0, r = n - 1;
    while(l <= r){
        if(!trn)
            b.push_back(a[l]),l++;
        else b.push_back(a[r]),r--;
        trn = !trn;
    }
    ll ret = abs(w - b[0]); 
    for(int i = 1; i < n; i++){
        ret += max(abs(b[i] - b[i - 1]), abs(b[i] - w));
    }
    reverse(b.begin(), b.end());
    ll cur = abs(w - b[0]);
    for(int i = 1; i < n; i++){
        cur += max(abs(b[i] - b[i - 1]), abs(b[i] - w));
    }
    return max(ret, cur);
}
int main()
{ 
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    ll w;
    cin>>n>>w; 
    for(int i = 0; i < n; i++)cin>>a[i];
    sort(a, a + n);
    ll ans_mn = abs(w - a[0]), ans_mx = max(f(w, 0), f(w, 1));
    for(int i = 1; i < n; i++){ 
        ans_mn += min(abs(a[i] - a[i - 1]), abs(a[i] - w));
    } 
    reverse(a, a + n);
    ll cur = abs(w - a[0]);
    for(int i = 1; i < n; i++){
        cur += min(abs(a[i] - a[i - 1]), abs(a[i] - w));
    }
    cout<<min({ans_mn, cur, abs(w - a[0]) + abs(w-a[n-1])})<<' '<<ans_mx;
    return 0;
}