/*
 * Race  [2112A]
 * Problem:  https://codeforces.com/problemset/problem/2112/A
 * Verdict:  ACCEPTED        Solved: 2025-08-31
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2112/submission/336322823
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
        int a,x,y;
        cin>>a>>x>>y;
        if(x>y)swap(x,y);
        if(a < x || a > y)cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}