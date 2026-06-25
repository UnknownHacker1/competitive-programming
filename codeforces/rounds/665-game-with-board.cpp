/*
 * Game with Board  [1841A]
 * Problem:  https://codeforces.com/problemset/problem/1841/A
 * Verdict:  ACCEPTED        Solved: 2025-03-21
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     constructive algorithms, games
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1841/submission/311656138
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
        int n;
        cin>>n;
        cout<<(n<=4?"Bob\n":"Alice\n");
    }
    return 0;
}