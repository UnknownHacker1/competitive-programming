/*
 * Suspicious logarithms  [1891D]
 * Problem:  https://codeforces.com/problemset/problem/1891/D
 * Verdict:  ACCEPTED        Solved: 2023-12-20
 * Language: C++20 (GCC 11-64)
 * Runtime:  935 ms     Memory: 1200 KB
 * Tags:     binary search, brute force, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1891/submission/238151151
 */

#include <bits/stdc++.h>
using ll = long long;
using ull = uint64_t;
using namespace std;  
ull mod = 1e9 + 7;
ull f(ull base, ull l, ull r){
    ull ret = 0;
    ull a,b;
    for(ull x = base, i = 1; ; i++){
        if(x * base - 1 < l) goto breh;
        a = max(x, l);
        b = min(x * base - 1, r);
        if(a <= b) ret += ((b - a + 1)%mod*i%mod)%mod;
        ret %= mod;
        breh:
        if(x * base <= r) x *= base;
        else break;
    }
    return ret;
}
int main()
{
    int q;
    cin>>q;
    while(q--){
        ll l,r;
        cin>>l>>r;
        ll ans = 0;
        for(ll i = 2, j = 1; i <= r; i <<= 1, j++){
            if(2 * i - 1 < l) continue;
            ll a = max(i, l);
            ll b = min(2 * i - 1, r);
            if(a <= b) ans += f(j, a, b);
            ans %= mod;
        }
        cout<<ans<<'\n';
    }
    return 0;
}