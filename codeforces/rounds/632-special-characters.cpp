/*
 * Special Characters  [1948A]
 * Problem:  https://codeforces.com/problemset/problem/1948/A
 * Verdict:  ACCEPTED        Solved: 2025-03-23
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  31 ms     Memory: 0 KB
 * Tags:     brute force, constructive algorithms
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1948/submission/312061974
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
int main()
{ 
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);  
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n & 1){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\nAA";
        n -= 2;
        while(n>0){
            cout << "BAA";
            n -= 2;
        } 
        cout<<'\n';
    }
    return 0;
}