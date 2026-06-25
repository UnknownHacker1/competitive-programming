/*
 * Beat The Odds  [1691A]
 * Problem:  https://codeforces.com/problemset/problem/1691/A
 * Verdict:  ACCEPTED        Solved: 2022-05-31
 * Language: C++20 (GCC 11-64)
 * Runtime:  31 ms     Memory: 0 KB
 * Tags:     brute force, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1691/submission/158985137
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
    int n,o=0;
    cin>>n;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        o+=(x&1);
    }
    cout<<min(n-o,o)<<'\n';
}
}