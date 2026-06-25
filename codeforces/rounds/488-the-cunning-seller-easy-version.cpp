/*
 * The Cunning Seller (easy version)  [2132C1]
 * Problem:  https://codeforces.com/problemset/problem/2132/C1
 * Verdict:  ACCEPTED        Solved: 2025-09-06
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2132/submission/337086337
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 3;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll ans = 0;
        for(int i = 19, x = 1162261467; i >= 0; i--, x /= 3){
            while(n>=x){
                n-=x;
                ans += (ll)3*x + i * (ll)x/3;
            } 
        }
        cout << ans << '\n';
    }
    return 0;
}