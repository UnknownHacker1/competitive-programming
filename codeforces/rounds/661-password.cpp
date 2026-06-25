/*
 * Password  [1743A]
 * Problem:  https://codeforces.com/problemset/problem/1743/A
 * Verdict:  ACCEPTED        Solved: 2024-02-27
 * Language: C++20 (GCC 11-64)
 * Runtime:  0 ms     Memory: 0 KB
 * Tags:     brute force, combinatorics, implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1743/submission/248475419
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
        int n,x;
        cin>>n;
        for(int i = 0; i < n; i++)cin>>x;
        n=10-n;
        cout<<6*n*(n-1)/2<<'\n';
    }
    return 0;
}