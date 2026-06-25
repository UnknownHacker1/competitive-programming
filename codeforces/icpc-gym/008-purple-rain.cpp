/*
 * Purple Rain  [101652S]
 * Problem:  Gym/ICPC contest 101652 - problem S
 * Verdict:  ACCEPTED        Solved: 2025-10-24
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  140 ms     Memory: 4200 KB
 * Tags:     n/a
 * Author:   team "balls" (HossamIsmail, BidoTeima, a1abay)
 * Source:   https://codeforces.com/gym/101652/submission/345434330
 */

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define int long long
using namespace std;

const int sz = 1e5 + 5, inf = 1e18 + 3, mod = 998244353;

int n, a[sz];

array<int, 3> f(string s, char c)
{
    n = s.size();
    fill(a, a + 1 + n, 0);
    for(int i = 0; i < n; i++)
    {
        a[i + 1] = (s[i] == c ? 1 : -1);
        a[i + 1] += a[i];
    }
    map<int, int> mp;
    mp[0] = 0;
    int l, r, mx = -inf;
    for(int i = 1; i <= n; i++)
    {
        int x = (*mp.begin()).first;
        if(a[i] - x > mx)
        {
            mx = a[i] - x;
            r = i;
            l = (*mp.begin()).second + 1;
        }
        if(mp.find(a[i]) == mp.end()) mp[a[i]] = i;
    }
    return {l, r, a[r] - a[l - 1]};
}

void solve()
{
    string s;
    cin >> s;
    array<int, 3> x = f(s, 'R');
    array<int, 3> y = f(s, 'B');
    if(x[2] > y[2]) cout << x[0] << " " << x[1];
    else if(x[2] < y[2]) cout << y[0] << " " << y[1];
    else
    {
        if(x[0] < y[0]) cout << x[0] << " " << x[1];
        else if(x[0] > y[0]) cout << y[0] << " " << y[1];
        else 
        {
            if(x[1] < y[1]) cout << x[0] << " " << x[1];
            else cout << y[0] << " " << y[1];
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