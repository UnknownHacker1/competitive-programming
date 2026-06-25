/*
 * Primes and Multiplication  [1228C]
 * Problem:  https://codeforces.com/problemset/problem/1228/C
 * Verdict:  ACCEPTED        Solved: 2022-01-20
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1228/submission/143409113
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
#define tc         \
    int tttttt,subtask;    \
    cin >> tttttt /*>> subtask*/; \
    while (tttttt--)

#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end()
ll mod = 1e9+7;
int64_t POW(int64_t a, int64_t b)
{
    if(b==0) return 1;
    a%=mod;
    int64_t res = POW(a,b/2);
    if(b&1)
        return (res%mod*res%mod*a%mod)%mod;
    return (res%mod*res%mod)%mod;
}
ll f(ll p, ll n){
    ll f = 0;
    while (n > 0) {
        f += (n/p);
        n /= p;
    }
    return f;
}
int main()
{
    ACPLS(); 
    ll n,b;
    cin>>b>>n;
    vector<ll>prm;
    for(ll i = 2; i * i <= b; i++){
        if(b%i==0){
            prm.push_back(i);
        }
        while(b%i==0){
            b/=i;
        }
    }
    if(b>1)prm.push_back(b);
    if(prm.empty()){
        cout<<0;
        return 0;
    }
    ll ans=1;
    for(ll p:prm){
        ans=(ans%mod*POW(p,f(p,n))%mod)%mod;
    }
    cout<<ans;
}


