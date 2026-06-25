/*
 * Turtle Math: Fast Three Task  [1933B]
 * Problem:  https://codeforces.com/problemset/problem/1933/B
 * Verdict:  ACCEPTED        Solved: 2025-11-06
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  77 ms     Memory: 0 KB
 * Tags:     implementation, math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1933/submission/347625584
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
#define int long long  

void solve()
{   
    int n;
    cin >> n; 
    bool b[3]{};
    int s=0,x;
    while(n--){
        cin>>x;
        x%=3;
        s=(s+x)%3;
        b[x]=1;
    }
    if(s==0){
        cout<<"0\n";
        return;
    }
    if(s == 2 || b[s]){
        cout<<"1\n";
        return;
    }
    cout<<"2\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);     

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}