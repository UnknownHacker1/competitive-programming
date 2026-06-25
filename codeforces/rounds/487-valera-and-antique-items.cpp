/*
 * Valera and Antique Items  [441A]
 * Problem:  https://codeforces.com/problemset/problem/441/A
 * Verdict:  ACCEPTED        Solved: 2021-03-24
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 100 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/441/submission/110913758
 */

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, v;
	cin >> n >> v;
	set<int> ans;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			if (x < v)ans.insert(i);
		}
	}
	cout << ans.size() << '\n';
	for (auto& i : ans)cout << i << ' ';
	return 0;
}
