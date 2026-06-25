/*
 * Turtle Puzzle: Rearrange and Negate  [1933A]
 * Problem:  https://codeforces.com/problemset/problem/1933/A
 * Verdict:  ACCEPTED        Solved: 2025-11-06
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     greedy, math, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1933/submission/347625231
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
#define int long long  

void solve()
{   
    int n;
    cin >> n;
    int ans = 0, x;
    while(n--){
        cin>>x;
        ans+=abs(x);
    }
    cout<<ans<<'\n';
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