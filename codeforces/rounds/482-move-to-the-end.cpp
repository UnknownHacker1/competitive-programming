/*
 * Move to the End  [2104B]
 * Problem:  https://codeforces.com/problemset/problem/2104/B
 * Verdict:  ACCEPTED        Solved: 2025-08-21
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  93 ms     Memory: 1000 KB
 * Tags:     brute force, data structures, dp, greedy, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2104/submission/334734850
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ll mx[n], sum[n];
        mx[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            mx[i] = max(a[i], mx[i - 1]);
        }
        sum[n - 1] = a[n - 1]; 
        for (int i = n - 2; i >= 0; i--)
        {
            sum[i] = a[i] + sum[i + 1]; 
        } 
        for (int k = 1; k <= n; k++)
        { 
            cout << sum[n - k] + max(0ll, (n > k ? mx[n - k - 1] - a[n - k] : 0ll)) << ' ';
        }
        cout << '\n';
    }
    return 0;
}