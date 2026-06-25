/*
 * Chocolate  [617B]
 * Problem:  https://codeforces.com/problemset/problem/617/B
 * Verdict:  ACCEPTED        Solved: 2021-04-02
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 0 KB
 * Tags:     combinatorics
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/617/submission/111782954
 */

#include "bits/stdc++.h"
using namespace std;
using ll = long long;

vector<int> a(105);
int n;
ll dp[105][2];
ll recurse(int idx, bool nutAvailable) {
    if (idx == n && nutAvailable) return 1;
    else if (idx == n) return 0;
    if (dp[idx][nutAvailable] != -1)
        return dp[idx][nutAvailable];

    if (a[idx])nutAvailable = 1;

    if (a[idx + 1] && nutAvailable) {
        return dp[idx][nutAvailable] = recurse(idx + 1, 0);
    }
    ll ret = 0;
    if (nutAvailable) ret += recurse(idx + 1, 0);
    ret += recurse(idx + 1, nutAvailable);
    return dp[idx][nutAvailable]=ret;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	cout << recurse(0, 0);
	return 0;
}
