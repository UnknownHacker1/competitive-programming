/*
 * Superhero Battle  [1141E]
 * Problem:  https://codeforces.com/problemset/problem/1141/E
 * Verdict:  ACCEPTED        Solved: 2025-03-25
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  108 ms     Memory: 800 KB
 * Tags:     math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1141/submission/312318778
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 3;
int d[N], n; 
int firstLess(ll h){ 
    for(int i = 0; i < n; i++){
        h += d[i];
        if(h <= 0) return i + 1;
    }
    return -1;
}
int main()
{ 
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);  
    ll h;
    cin>>h>>n; 
    ll ans=-1;
    ll sum=0;
    ll mnPref=0;
    for(int i = 0; i < n; i++){
        cin>>d[i]; 
        sum += d[i];
        mnPref=min(mnPref,sum);
    }
    ans = firstLess(h);
    if(ans != -1 || sum >= 0){
        cout<<ans;
        return 0;
    } 
    // do until h + a*sum + minPref <= 0 
    // h + a*sum <= -minPref 
    // a*sum <= -minPref-h
    // a >= (-minPref-h)/sum
    ll a = (-mnPref-h + sum + 1)/sum;
    //cout << a << ' ';
    ans = a*n;
    h += a*sum;
    //cout << h << ' ';
    ans += firstLess(h);
    cout << ans;
    return 0;
}