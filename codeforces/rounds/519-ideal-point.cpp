/*
 * Ideal Point  [1795B]
 * Problem:  https://codeforces.com/problemset/problem/1795/B
 * Verdict:  ACCEPTED        Solved: 2025-03-20
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  77 ms     Memory: 0 KB
 * Tags:     brute force, geometry, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1795/submission/311526600
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
        int n,k;
        cin>>n>>k;
        bool existl=0,existr=0;
        for(int i = 0; i < n; i++){
            int l,r;
            cin>>l>>r;
            if(l==k)existl=1;
            if(r==k)existr=1;
        }
        cout<<(existl&&existr?"YES\n":"NO\n");
    }
    return 0;
}