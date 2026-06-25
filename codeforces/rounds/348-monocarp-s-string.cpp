/*
 * Monocarp's String  [2145C]
 * Problem:  https://codeforces.com/problemset/problem/2145/C
 * Verdict:  ACCEPTED        Solved: 2025-10-27
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  93 ms     Memory: 11000 KB
 * Tags:     binary search, greedy, strings
 * Author:   team "balls" (HossamIsmail, BidoTeima, a1abay)
 * Source:   https://codeforces.com/contest/2145/submission/345959464
 */

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define int long long
using namespace std;

const int sz = 1030, inf = 1e18 + 3, mod = 998244353;

void solve()
{
    int n;
    cin>>n;
    int pre[n+1]{};
    for(int i = 1; i <= n; i++){
        char ch;
        cin >> ch;
        if(ch == 'a') pre[i] = 1;
        else pre[i] = -1;
        pre[i] += pre[i - 1];
    }
    // pre[n] = 0 for condition to be true 

    // so pre[n] - (pre[r] - pre[l - 1]) == 0
    // pre[n ] - pre[r] + pre[l - 1] == 0
    // fix r
    // pre[l - 1] = pre[r] - pre[n - 1]
    map<int,int>closest;
    closest[0] = 0;

    int ans = n;
    if(pre[n]==0)ans=0;
    for(int r = 1; r <= n; r++){
        auto it = closest.find(pre[r] - pre[n]);

        if(it != closest.end()){
            ans = min(ans, r - it->second);
        }
        closest[pre[r]] = r;
    }
    cout << (ans == n ? -1 : ans) << '\n';
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