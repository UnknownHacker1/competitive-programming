/*
 * Valuable Cards  [1992F]
 * Problem:  https://codeforces.com/problemset/problem/1992/F
 * Verdict:  ACCEPTED        Solved: 2025-11-01
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  468 ms     Memory: 800 KB
 * Tags:     brute force, dp, greedy, number theory, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1992/submission/346891743
 */

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define int long long
using namespace std;

const int sz = 1e5 + 5, inf = 1e18 + 3, mod = 998244353;
int n, x, a[sz];

int f()
{
    vector<int> dv;
    for(int i = 1; i * i <= x; i++)
    {
        if(x % i) continue;
        dv.push_back(i);
        if(x / i != i) dv.push_back(x / i);
    }
    sort(all(dv));
    int l = 1, cnt = 1;
    vector<int> dp(x + 1, 0);
    for(int i = 1; i <= n; i++)
    {
        if(x % a[i]) continue;
        if(dp[x / a[i]]) 
        {
            l = i;
            dp.assign(x + 1, 0);
            dp[a[i]] |= 1;
            cnt++;
        }else{
            for(int j = dv.size() - 1; j >= 0; j--)
            {
                if(x % (dv[j] * a[i]) == 0) dp[dv[j] * a[i]] |= dp[dv[j]];
            }
            dp[a[i]] |= 1;
        }
    }
    return cnt;
}

void solve()
{ 
    cin >> n >> x;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int mn = f();
    reverse(a + 1, a + 1 + n);
    cout << min(mn, f()) << '\n';
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