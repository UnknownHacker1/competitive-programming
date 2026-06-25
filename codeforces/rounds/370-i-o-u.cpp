/*
 * I.O.U.  [376B]
 * Problem:  https://codeforces.com/problemset/problem/376/B
 * Verdict:  ACCEPTED        Solved: 2021-04-02
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 0 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/376/submission/111773427
 */

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<ll> arr(105, 0);
	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a] -= c;
		arr[b] += c;
	}
	ll res = 0;
	for (auto& i : arr) {
		if (i > 0)res += i;
	}
	cout << res;
	return 0;
}
