/*
 * Napoleon Cake  [1501B]
 * Problem:  https://codeforces.com/problemset/problem/1501/B
 * Verdict:  ACCEPTED        Solved: 2021-03-13
 * Language: C++17 (GCC 7-32)
 * Runtime:  93 ms     Memory: 3100 KB
 * Tags:     dp, implementation, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1501/submission/109863189
 */

#include "bits/stdc++.h"

using namespace std;
using ll = long long;
ll ceili(ll x, ll y) {
	return (x + y - 1) / y;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		vector<ll> a(n);
		for (auto& i : a)cin >> i;
		vector<ll> diffarr(n + 5, 0);
		for (int i = 0; i < n; i++) {
			++diffarr[max(0ll, i - a[i] + 1)];
			--diffarr[i + 1];
		}
		for (int i = 1; i < n; i++) diffarr[i] += diffarr[i - 1];
		for (int i = 0; i < n; i++) {
			cout << bool(diffarr[i]) << ' ';
		}
		cout << '\n';
	}
	return 0;
}
