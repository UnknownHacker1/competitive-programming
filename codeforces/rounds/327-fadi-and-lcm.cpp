/*
 * Fadi and LCM  [1285C]
 * Problem:  https://codeforces.com/problemset/problem/1285/C
 * Verdict:  ACCEPTED        Solved: 2022-07-18
 * Language: C++20 (GCC 11-64)
 * Runtime:  31 ms     Memory: 0 KB
 * Tags:     brute force, math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1285/submission/164807195
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
int main()
{
    ACPLS();   
    ll X;
    cin>>X;
    vector<ll>div;
    ll a = 1e18, b = 1e18;
    for(ll i = 1; i * i <= X; i++){
        if(X%i==0&&__gcd(i,X/i)==1&&max(i,X/i)<max(a,b)){
            a=i,b=X/i;
        }
    }
    cout<<a<<' '<<b;
}