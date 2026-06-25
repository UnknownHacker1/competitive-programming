/*
 * Just Eat It!  [1285B]
 * Problem:  https://codeforces.com/problemset/problem/1285/B
 * Verdict:  ACCEPTED        Solved: 2022-07-18
 * Language: C++20 (GCC 11-64)
 * Runtime:  31 ms     Memory: 800 KB
 * Tags:     dp, greedy, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1285/submission/164804520
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
tc{ 
    int n;
    cin>>n;
    ll a[n],sum=0;
    for(ll&i:a)cin>>i,sum+=i;
    ll cur=0,mx=-1e18;
    for(int i = 0; i < n-1; i++){
        cur+=a[i];
        cur=max(cur,a[i]);
        mx=max(mx,cur);
    }
    cur=0;
    for(int i = 1; i < n; i++){
        cur+=a[i];
        cur=max(cur,a[i]);
        mx=max(mx,cur);
    }
    cout<<(sum>mx?"YES\n":"NO\n");
}
}