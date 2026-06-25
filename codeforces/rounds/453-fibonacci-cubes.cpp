/*
 * Fibonacci Cubes  [2111B]
 * Problem:  https://codeforces.com/problemset/problem/2111/B
 * Verdict:  ACCEPTED        Solved: 2025-08-29
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  156 ms     Memory: 0 KB
 * Tags:     brute force, dp, implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2111/submission/336073596
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
        int n,m;
        cin>>n>>m;
        int f[n+1];
        f[1] = 1;
        f[2] = 2;
        for(int i = 3; i <= n; i++) f[i] = f[i - 1] + f[i - 2];
        for(int i = 0; i < m; i++){
            int w,l,h;
            cin>>w>>l>>h;
            if(max({w,l,h}) >= f[n]+f[n-1] && min({w,l,h}) >= f[n])cout<<1;
            else cout<<0;
        }
        cout<<'\n';
    }
    return 0;
}