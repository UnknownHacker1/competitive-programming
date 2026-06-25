/*
 * Anti-knapsack  [1493A]
 * Problem:  https://codeforces.com/problemset/problem/1493/A
 * Verdict:  ACCEPTED        Solved: 2021-03-06
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 200 KB
 * Tags:     constructive algorithms, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1493/submission/109278320
 */

#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		bool is[1005];
		memset(is, 0, sizeof(is));
		is[0] = 1;
		vector<int> ans;
		for (int i = n; i >= 1; i--) {
			if (i > k || is[k - i] == 0) {
				is[i] = 1;
				ans.push_back(i);
			}
		}
		cout << ans.size() << '\n';
		for (auto& i : ans)cout << i << ' ';
		cout << '\n';
	}
	return 0;
}
