/*
 * Halfway  [101652Q]
 * Problem:  Gym/ICPC contest 101652 - problem Q
 * Verdict:  ACCEPTED        Solved: 2025-10-24
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  62 ms     Memory: 100 KB
 * Tags:     n/a
 * Author:   team "balls" (HossamIsmail, BidoTeima, a1abay)
 * Source:   https://codeforces.com/gym/101652/submission/345431844
 */

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define int long long
using namespace std;

const int sz = 2e2 + 5, inf = 1e18 + 3, mod = 998244353;

int n;

void solve()
{
    cin >> n;
    int l = 1, r = n;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(m * n - m * (m + 1) / 2 >= (n - 1) * n / 4) r = m - 1;
        else l = m + 1;
        
    }
    for(int i = r-2; i<=r+2; i++){
        if((long double)i * (long double)n - (long double)i * (i + 1) / (long double)2 >=((long double)n - 1) * (long double)n / 4){
            cout << i;
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