/*
 * Stock Arbitraging  [1150A]
 * Problem:  https://codeforces.com/problemset/problem/1150/A
 * Verdict:  ACCEPTED        Solved: 2022-07-18
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     greedy, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1150/submission/164818557
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
    int n,m,r;
    cin>>n>>m>>r;
    int s[n],b[m];
    for(int&i:s)cin>>i;
    for(int&i:b)cin>>i;
    cout<<max(r,r/(*min_element(s,s+n))*(*max_element(b,b+m))+(r%(*min_element(s,s+n))));
}