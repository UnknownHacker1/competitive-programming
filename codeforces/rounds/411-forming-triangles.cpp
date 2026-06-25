/*
 * Forming Triangles  [1922B]
 * Problem:  https://codeforces.com/problemset/problem/1922/B
 * Verdict:  ACCEPTED        Solved: 2025-03-22
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  93 ms     Memory: 0 KB
 * Tags:     combinatorics, constructive algorithms, math, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1922/submission/311923287
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
int main()
{ 
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);  
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int freq[n+1]{},x,pref[n+1]{};
        for(int i = 0; i < n; i++){
            cin>>x;
            ++freq[x];
        }
        pref[0]=freq[0];
        for(int i = 1; i <= n; i++)pref[i]=pref[i-1]+freq[i];
        ll ans = freq[0]*1ll*(freq[0]-1)*(freq[0]-2)/6;
        for(int i = 1; i <= n; i++){
            ans += freq[i]*1ll*(freq[i]-1)*(freq[i]-2)/6;
            ans += freq[i]*1ll*(freq[i]-1)/2*pref[i-1];
        }
        cout<<ans<<'\n';
    }
    return 0;
}