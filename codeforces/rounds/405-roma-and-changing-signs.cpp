/*
 * Roma and Changing Signs  [262B]
 * Problem:  https://codeforces.com/problemset/problem/262/B
 * Verdict:  ACCEPTED        Solved: 2021-03-07
 * Language: C++17 (GCC 7-32)
 * Runtime:  248 ms     Memory: 1600 KB
 * Tags:     greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/262/submission/109330999
 */

#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<ll> neg;
	ll sum = 0;
	ll mn=LLONG_MAX;
	for (int i = 0; i < n; i++) {
		ll num;
		cin >> num;
		sum += num;
		mn = min(mn, abs(num));
		if (num <= 0) neg.push_back(abs(num));
	}
	sort(neg.rbegin(), neg.rend());
	int i = 0; 

	while (k > 0 && i < (int)neg.size()) {
		sum += neg[i] * 2;
		++i;
		--k;
	}

	if (k % 2) sum -= (mn*2);

	cout << sum << '\n';
	return 0;
}
