/*
 * Straight Shot  [101652R]
 * Problem:  Gym/ICPC contest 101652 - problem R
 * Verdict:  ACCEPTED        Solved: 2025-10-24
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     n/a
 * Author:   team "balls" (HossamIsmail, BidoTeima, a1abay)
 * Source:   https://codeforces.com/gym/101652/submission/345438694
 */

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define int long long
using namespace std;

const int sz = 1e2 + 5, inf = 1e18 + 3, mod = 998244353;
const long double pre = 0.00000000001;

int n;
long double X, V, l[sz], r[sz], v[sz];

void solve()
{
    cin >> n >> X >> V;
    for(int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i] >> v[i];
    }  
    long double lvy = -V, rvy = V;
    while(rvy - lvy >= pre)
    {
        long double vy = (lvy + rvy) / 2, Y = 0;
        long double vx = sqrt(V * V - vy * vy);
        long double rest = X;
        for(int i = 1; i <= n; i++)
        {
            Y += (r[i] - l[i]) / vx * (v[i] + vy);
            rest -= r[i] - l[i];
        }
        Y += rest / vx * vy;
        if(Y >= 0) rvy = vy - pre;
        else lvy = vy + pre;
    }
    long double vy = rvy + pre;
    if(V * V - vy * vy < 0) 
    {
        cout << "Too hard";
        return;
    }
    long double vx = sqrt(V * V - vy * vy);
    if(V / vx > 2)
    {
        cout << "Too hard";
        return;
    }
    cout << fixed << setprecision(3) << X / vx;
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