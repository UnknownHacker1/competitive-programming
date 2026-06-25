/*
 * Energy Crystals  [2111A]
 * Problem:  https://codeforces.com/problemset/problem/2111/A
 * Verdict:  ACCEPTED        Solved: 2025-08-29
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     greedy, implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2111/submission/336071850
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
        int x;
        cin>>x; 
        int lg2=0;
        while(x>1){
            x/=2;
            lg2++;
        }
        cout<<2*lg2+3<<'\n';
    }
    return 0;
}