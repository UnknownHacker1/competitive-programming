/*
 * Meximization  [1497A]
 * Problem:  https://codeforces.com/problemset/problem/1497/A
 * Verdict:  ACCEPTED        Solved: 2021-03-17
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 200 KB
 * Tags:     brute force, data structures, greedy, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1497/submission/110189134
 */

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> a(n);
		vector<ll> freq(105, 0);
		for (auto& i : a) cin >> i, freq[i]++;
		vector<ll>ans;
		for (int i = 0; ans.size() < a.size(); i++, i%=101) {
			if (freq[i]>0) ans.push_back(i);
			--freq[i];
		}
		for (auto& i : ans)cout << i << ' ';
		cout << '\n';
	}
    return 0;
}
