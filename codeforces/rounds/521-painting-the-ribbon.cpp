/*
 * Painting the Ribbon  [1954A]
 * Problem:  https://codeforces.com/problemset/problem/1954/A
 * Verdict:  ACCEPTED        Solved: 2025-03-18
 * Language: C++17 (GCC 7-32)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     constructive algorithms, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1954/submission/311327208
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
        int n,m,k;
        cin>>n>>m>>k;
        /*if(m == 1){
            cout<<"NO\n";
            continue;
        }*/
        cout<<(k >= n - ((n+m-1)/m) ? "NO\n" : "YES\n");
    }
    return 0;
}