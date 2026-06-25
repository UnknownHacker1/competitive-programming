/*
 * Water the Trees  [1661C]
 * Problem:  https://codeforces.com/problemset/problem/1661/C
 * Verdict:  ACCEPTED        Solved: 2024-03-05
 * Language: C++20 (GCC 11-64)
 * Runtime:  264 ms     Memory: 4700 KB
 * Tags:     binary search, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1661/submission/249737709
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;       
int ok(ll lim, vector<ll>a, int n){
    ll sm = 0, mx = *max_element(a.begin(), a.end());
    ll l = lim;
    for(int i = 0; i < n; i++){ 
        int d = min(lim, (mx - a[i]))/2;
        lim -= 2 * d; 
        sm += mx - a[i] - 2 * d;
    } 
    if(2 * sm - 1 <= l) return 1;
    lim = l, sm = 0, mx++;
    for(int i = 0; i < n; i++){ 
        int d = min(lim, (mx - a[i]))/2;
        lim -= 2 * d; 
        sm += mx - a[i] - 2 * d;
    } 
    return 2 * sm - 1 <= l;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>a(n);
        for(auto&i:a)cin>>i;
        sort(a.begin(),a.end());
        if(a[0]==a[n-1]){
            cout<<"0\n";
            continue;
        }
        ll lo = 1, hi = 1e18, ans = hi, mid;
        while(lo <= hi){
            mid = (lo + hi) >> 1;
            if(ok(mid, a, n)){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}