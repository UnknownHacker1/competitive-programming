/*
 * Problem for Nazar  [1151C]
 * Problem:  https://codeforces.com/problemset/problem/1151/C
 * Verdict:  ACCEPTED        Solved: 2022-06-26
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 1200 KB
 * Tags:     constructive algorithms, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1151/submission/161869626
 */

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
#define tc int tttt;cin>>tttt;while(tttt--)
ll mod = 1e9+7;
ll sumNOdd(ll n){
    return ((n%mod)*(n%mod))%mod;
}
ll sumNEven(ll n){
    return ((n%mod)*((n+1)%mod))%mod;
}
ll calc(ll n){
    // ans for 1 to n
    ll ans=0,pw2=1,cntodd=0,cnteven=0;
    bool trn=1;// 1 -> odd, 0 -> even
    while(cntodd+cnteven<n){
        ll v = min(pw2,n-(cntodd+cnteven));
        if(trn){
            ans+=(sumNOdd(cntodd+v)+mod-sumNOdd(cntodd));
            ans%=mod;
            cntodd+=v;
        }
        else{
            ans+=(sumNEven(cnteven+v)+mod-sumNEven(cnteven));
            ans%=mod;
            cnteven+=v;
        }
        trn^=1;
        pw2*=2;
    }
    return ans;
}
int main()
{
    ACPLS();   
    ll l,r;
    cin>>l>>r;
    cout<<(calc(r)+mod-calc(l-1))%mod;
}
