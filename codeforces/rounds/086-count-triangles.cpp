/*
 * Count Triangles  [1355C]
 * Problem:  https://codeforces.com/problemset/problem/1355/C
 * Verdict:  ACCEPTED        Solved: 2022-06-29
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     binary search, implementation, math, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1355/submission/162284162
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
ll summation(ll l, ll r){
    if(l>r)
        return 0; 
    return r*(r+1)/2 - l*(l-1)/2;
}
ll calc(ll c, ll x, ll y){
    if(y>=c)
        return summation(c-min(c,x)+1,c+1);
    ll d = c-y;
    ll ret = (y+1)*min(d+1,x+1);
    x-=min(d,x);
    return ret+summation(max(0ll,y-x+1), y);
}
int main()
{
    ACPLS();    
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ans=0;
    for(ll x = a; x <= b; x++){
        ans+=calc(x-1,c-b,d-c);
    }
    cout<<ans;
}