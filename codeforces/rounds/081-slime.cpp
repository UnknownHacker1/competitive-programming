/*
 * Slime  [1038D]
 * Problem:  https://codeforces.com/problemset/problem/1038/D
 * Verdict:  ACCEPTED        Solved: 2022-06-08
 * Language: C++20 (GCC 11-64)
 * Runtime:  78 ms     Memory: 2000 KB
 * Tags:     dp, greedy, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1038/submission/159932809
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
    int n;
    cin>>n;
    int a[n];
    ll s=0; 
    bool pos=0;
    bool neg=0;
    for(auto&i:a){
        cin>>i;
        s+=abs(i);
        pos|=(i>=0);
        neg|=(i<0);
    }
    if(n==1){
        cout<<a[0];
        return 0;
    }
    int mn = 2e9;
    for(int i = 0; i<n; i++){
        mn=min(mn,abs(a[i]));
    }
    if(pos&&neg)
        cout<<s;
    else cout<<s-2*mn;
}