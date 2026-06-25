/*
 * Alexey and Train  [1501A]
 * Problem:  https://codeforces.com/problemset/problem/1501/A
 * Verdict:  ACCEPTED        Solved: 2021-03-13
 * Language: C++17 (GCC 7-32)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1501/submission/109869809
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
		vector<ll> a(n), b(n), tm(n);
		for (int i = 0; i < n; i++)
			cin >> a[i] >> b[i];
		for (int i = 0; i < n; i++)
			cin >> tm[i];
		ll tot = a[0]+tm[0];
		if(n>1)tot += ceili(b[0] - a[0], 2);
		if(n>1)tot = max(tot, b[0]);
		for (int i = 1; i < n; i++) {
			tot += (a[i] - b[i - 1] + tm[i]);
			if(i<n-1)tot += ceili(b[i] - a[i], 2);
			if(i<n-1)tot = max(tot, b[i]);
		}
		cout << tot << '\n';
	}
	return 0;
}
