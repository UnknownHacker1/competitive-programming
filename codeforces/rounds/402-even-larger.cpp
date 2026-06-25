/*
 * Even Larger  [2134C]
 * Problem:  https://codeforces.com/problemset/problem/2134/C
 * Verdict:  ACCEPTED        Solved: 2025-09-03
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  78 ms     Memory: 0 KB
 * Tags:     brute force, greedy, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2134/submission/336702673
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 3;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll a[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        ll ans = 0;
        for(int i = 1; i + 1 <= n; i++){
            if(i & 1){
                if(a[i + 1] < a[i]){
                    ans += a[i] - a[i + 1];
                    a[i] = a[i + 1];
                }
            }else{
                if(a[i] < a[i + 1]){
                    ans += a[i + 1] - a[i];
                    a[i + 1] = a[i];
                }
            }
        }
        for(int i = 1; i + 2 <= n; i += 2){
            if(a[i + 1] < a[i] + a[i + 2]){
                ans += a[i] + a[i + 2] - a[i + 1];
                a[i + 2] -= a[i] + a[i + 2] - a[i + 1];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}