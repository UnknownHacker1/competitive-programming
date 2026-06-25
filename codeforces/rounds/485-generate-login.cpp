/*
 * Generate Login  [909A]
 * Problem:  https://codeforces.com/problemset/problem/909/A
 * Verdict:  ACCEPTED        Solved: 2021-03-24
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 0 KB
 * Tags:     brute force, greedy, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/909/submission/110914769
 */

#include "bits/stdc++.h"

using namespace std;
using ll = long long;
string alpha_early_comp(string a, string b) {
	if (b.substr(0, a.length()) == a)return a;
	if (a.substr(0, b.length()) == b)return b;
	for (int i = 0; i < (int)min(a.size(), b.size()); i++) {
		if (a[i] < b[i])return a;
		else if (a[i] > b[i])return b;
	}
	return a;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a, b;
	cin >> a >> b;
	string ans = a.substr(0,1) + b.substr(0,1);
	for (int i = 1; i <= (int)a.size(); i++) {
		for (int j = 1; j <= (int)b.size(); j++) {
			ans = alpha_early_comp(ans, a.substr(0, i) + b.substr(0, j));
		}
	}
	cout << ans;
	return 0;
}
