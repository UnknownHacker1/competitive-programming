/*
 * Maximal AND  [1669H]
 * Problem:  https://codeforces.com/problemset/problem/1669/H
 * Verdict:  ACCEPTED        Solved: 2022-04-21
 * Language: C++20 (GCC 11-64)
 * Runtime:  61 ms     Memory: 0 KB
 * Tags:     bitmasks, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1669/submission/154369099
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
#define tc int tttt;cin>>tttt;while(tttt--)
int main()
{
    ACPLS(); 
tc{
    ll n,k;
    cin>>n>>k;
    ll freq[31]{};
    for(int i = 0; i < n; i++){
        ll x;
        cin>>x;
        for(int j = 0; j < 31; j++){
            if(x&(1<<j))freq[j]++;
        }
    }
    ll ans=0;
    for(int j = 30; j >= 0; j--){
        if(k>=n-freq[j]){
            ans+=(1<<j);
            k-=n-freq[j];
        }
    }
    cout<<ans<<'\n';
}
}