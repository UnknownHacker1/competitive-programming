/*
 * Busy Robot  [1463C]
 * Problem:  https://codeforces.com/problemset/problem/1463/C
 * Verdict:  ACCEPTED        Solved: 2022-08-23
 * Language: C++20 (GCC 11-64)
 * Runtime:  46 ms     Memory: 1600 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1463/submission/169440214
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
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
    ll t[n+1];
    ll x[n];
    for(int i = 0; i < n; i++){
        cin>>t[i]>>x[i];
    }
    t[n] = 1e18;
    ll cur = 0;
    int ans = 0;
    for(int i = 0; i < n; ){
        //cout<<t[i]<<" h\n";
        ll dist = abs(cur - x[i]);
        int idx = lower_bound(t + i + 1, t + n, t[i] + dist) - t;
        int v = (cur < x[i] ? 1 : -1);
        for(int j = i; j < idx; j++){
            ll c = cur + v * (t[j] - t[i]);
            if(c + v * abs(x[j] - c) == x[j] && t[j] - t[i] + abs(x[j] - c) <= dist && t[j] + abs(x[j] - c) <= t[j+1]){
                ans++;
            }
        }
        cur = x[i];
        i = idx;
    }
    cout<<ans<<'\n';
}
}   