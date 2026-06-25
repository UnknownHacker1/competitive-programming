/*
 * Patchouli's Magical Talisman  [1688B]
 * Problem:  https://codeforces.com/problemset/problem/1688/B
 * Verdict:  ACCEPTED        Solved: 2022-06-03
 * Language: C++20 (GCC 11-64)
 * Runtime:  46 ms     Memory: 1600 KB
 * Tags:     bitmasks, constructive algorithms, greedy, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1688/submission/159359172
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
    ll a[n];
    int odd=0;
    for(auto&i:a)cin>>i,odd+=(i&1); 
    if(odd>0){
        cout<<n-odd<<'\n';
        continue;
    }
    int mn=1e9;
    for(int i:a){
        int x = i;
        int cnt=0;
        while(x%2==0){
            x/=2;
            cnt++;
        }
        mn=min(mn,cnt);
    }
    cout<<n-1+mn<<'\n';
}
}