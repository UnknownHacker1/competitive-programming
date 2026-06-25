/*
 * Odd Palindrome  [101652N]
 * Problem:  Gym/ICPC contest 101652 - problem N
 * Verdict:  ACCEPTED        Solved: 2025-10-24
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  46 ms     Memory: 4700 KB
 * Tags:     n/a
 * Author:   team "balls" (HossamIsmail, BidoTeima, a1abay)
 * Source:   https://codeforces.com/gym/101652/submission/345428179
 */

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define int long long
using namespace std;

const int sz = 3e5 + 5, inf = 1e18 + 3, mod = 998244353;

int n, pre[sz], suff[sz];

void solve()
{
    string s;
    cin >> s;
    bool ok = 1;
    for(int i = 0; i < s.size() - 1; i++)
    {
        ok &= s[i] != s[i + 1];
    }
    cout << (ok ? "Odd" : "Or not") << '.';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}