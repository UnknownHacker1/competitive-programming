/*
 * Forbidden Zero  [101652Z]
 * Problem:  Gym/ICPC contest 101652 - problem Z
 * Verdict:  ACCEPTED        Solved: 2025-10-24
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  46 ms     Memory: 100 KB
 * Tags:     n/a
 * Author:   team "balls" (HossamIsmail, BidoTeima, a1abay)
 * Source:   https://codeforces.com/gym/101652/submission/345430406
 */

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define int long long
using namespace std;

const int sz = 2e2 + 5, inf = 1e18 + 3, mod = 998244353;

int n, row[40][40], col[40][40], a[40][40];

void solve()
{
    cin >> n;
    n++;
    while(1)
    {
        string s = to_string(n);
        if(s.find('0') != s.npos) n++;
        else 
        {
            cout << n << '\n';
            return;
        }
    }
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