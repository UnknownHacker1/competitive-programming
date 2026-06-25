/*
 * Mezo Playing Zoma  [1285A]
 * Problem:  https://codeforces.com/problemset/problem/1285/A
 * Verdict:  ACCEPTED        Solved: 2022-07-18
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 300 KB
 * Tags:     math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1285/submission/164803891
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
    string s;
    cin>>n>>s;
    cout<<n+1;
}