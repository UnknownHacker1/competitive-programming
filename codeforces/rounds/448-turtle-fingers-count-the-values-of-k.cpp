/*
 * Turtle Fingers: Count the Values of k  [1933C]
 * Problem:  https://codeforces.com/problemset/problem/1933/C
 * Verdict:  ACCEPTED        Solved: 2025-11-06
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  155 ms     Memory: 0 KB
 * Tags:     brute force, implementation, math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1933/submission/347626178
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
#define int long long  

void solve()
{   
    int a,b,l;
    cin>>a>>b>>l;
    int ans = 0;
    set<int>st;
    for(int pa = 1; pa <= 1e6; pa *= a){ 
        for(int pb = 1; pb <= 1e6; pb *= b){
            if(l % (pa * pb) == 0){
                st.insert(l/(pa*pb));
            }
        } 
    }
    cout << (int)st.size() << '\n';
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