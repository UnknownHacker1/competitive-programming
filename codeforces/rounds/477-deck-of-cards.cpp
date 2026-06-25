/*
 * Deck of Cards  [2145B]
 * Problem:  https://codeforces.com/problemset/problem/2145/B
 * Verdict:  ACCEPTED        Solved: 2025-10-27
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     greedy, implementation
 * Author:   team "balls" (HossamIsmail, BidoTeima, a1abay)
 * Source:   https://codeforces.com/contest/2145/submission/345960182
 */

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define int long long
using namespace std;

const int sz = 1030, inf = 1e18 + 3, mod = 998244353;

int k, n;
string s;

void solve()
{
    cin >> n >> k >> s;
    int t = count(all(s), '2');
    int z = count(all(s), '0');
    int o = count(all(s), '1');
    string res(n + 1, '+');
    for(int i = 1; i <= z; i++) res[i] = '-';
    for(int i = n; i > n - o; i--) res[i] = '-';
    int l = z + 1, r = n - o;
    if(r - l + 1 == t)
    {
        for(int i = l; i <= r; i++) res[i] = '-';
    }
    else 
    {
        for(int i = l; i <= l + t - 1; i++) res[i] = '?';
        for(int i = r - t + 1; i <= r; i++) res[i] = '?';
    }
    for(int i = 1; i <= n; i++) cout << res[i];
    cout << '\n';
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