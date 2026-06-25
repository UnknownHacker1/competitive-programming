/*
 * Shape Perimeter  [2056A]
 * Problem:  https://codeforces.com/problemset/problem/2056/A
 * Verdict:  ACCEPTED        Solved: 2025-11-03
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  61 ms     Memory: 0 KB
 * Tags:     constructive algorithms, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2056/submission/347180052
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
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int ans = 0;

        for(int i = 0; i < n; i++){
            int x,y;
            cin >> x >> y;
            ans = ans + 2 * m - (i==0?0:(m-x)+(m-y)); 
        } 
        cout << 2*ans << '\n';
    }
    return 0;
}