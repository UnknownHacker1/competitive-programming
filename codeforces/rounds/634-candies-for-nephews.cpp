/*
 * Candies for Nephews  [2145A]
 * Problem:  https://codeforces.com/problemset/problem/2145/A
 * Verdict:  ACCEPTED        Solved: 2025-10-27
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     math
 * Author:   team "balls" (HossamIsmail, BidoTeima, a1abay)
 * Source:   https://codeforces.com/contest/2145/submission/345958982
 */

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define int long long
using namespace std;

const int sz = 1030, inf = 1e18 + 3, mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    cout << (3 - n % 3) % 3 << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
}