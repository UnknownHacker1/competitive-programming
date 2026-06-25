/*
 * Parkway Walk  [1697A]
 * Problem:  https://codeforces.com/problemset/problem/1697/A
 * Verdict:  ACCEPTED        Solved: 2025-03-17
 * Language: C++17 (GCC 7-32)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     greedy, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1697/submission/311023492
 */

#include <bits/stdc++.h>
using namespace std; 
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m,s=0,x;
        cin>>n>>m;
        while(n--)cin>>x,s+=x;
        cout<<max(0,s-m)<<'\n';
    }
    return 0;
}