/*
 * Geometry Horse  [175C]
 * Problem:  https://codeforces.com/problemset/problem/175/C
 * Verdict:  ACCEPTED        Solved: 2023-08-11
 * Language: C++17 (GCC 7-32)
 * Runtime:  30 ms     Memory: 0 KB
 * Tags:     greedy, implementation, sortings, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/175/submission/218288499
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin>>n;
    pair<int,int>a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i].second>>a[i].first;
    }
    sort(a,a+n);
    int t;
    cin>>t;
    ll p[t];
    for(int i = 0; i < t; i++){
        cin>>p[i];
    }
    int f = 1;
    ll k = 0, ans = 0;
    for(int i = 0; i < n; i++){
        while(a[i].second > 0 && f<=t){
            ll mn = min(p[f - 1] - k, (ll)a[i].second);
            k += mn;
            a[i].second -= mn;
            ans += mn * a[i].first * f;
            if(k >= p[f - 1])++f;
        }
        if(f==t+1){
           ans+=(ll)a[i].second*a[i].first*f;
        }
    }
    cout<<ans;
    return 0;
}