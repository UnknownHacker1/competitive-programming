/*
 * Walk on Matrix  [1332D]
 * Problem:  https://codeforces.com/problemset/problem/1332/D
 * Verdict:  ACCEPTED        Solved: 2022-03-28
 * Language: C++17 (GCC 9-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     bitmasks, constructive algorithms, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1332/submission/151272870
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
#define tc         \
    int tttttt,subtask;    \
    cin >> tttttt /*>> subtask*/; \
    while (tttttt--)
 
#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end()  

int main()
{
    ACPLS();   
    int k;
    cin>>k;
    cout<<"3 3\n";
    cout<<"262143 262143 131072\n262143 "<<k<<" 262143\n131072 262143 "<<k;
}