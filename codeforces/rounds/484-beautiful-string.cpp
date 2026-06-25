/*
 * Beautiful String  [2162B]
 * Problem:  https://codeforces.com/problemset/problem/2162/B
 * Verdict:  ACCEPTED        Solved: 2025-10-19
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  62 ms     Memory: 0 KB
 * Tags:     brute force, constructive algorithms
 * Author:   team "balls" (HossamIsmail, BidoTeima, a1abay)
 * Source:   https://codeforces.com/contest/2162/submission/344576338
 */

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define int long long
using namespace std;

const int sz = 5e5 + 5, inf = 1e18 + 3, mod = 998244353;

int n;
string s;

void solve()
{
    cin >> n >> s; 
    cout << count(all(s), '0') << '\n';
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '0') cout << i + 1 << ' ';
    }
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