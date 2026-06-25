/*
 * Strange Table  [1506A]
 * Problem:  https://codeforces.com/problemset/problem/1506/A
 * Verdict:  ACCEPTED        Solved: 2021-03-25
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 0 KB
 * Tags:     math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1506/submission/111025773
 */

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tt = 1;
	cin >> tt;
	for(int i = 1; i <= tt; i++) {
		//cout << "TC " << i << ": ";
		ll n, m, x;
		cin >> n >> m >> x;
		ll div = (x % n == 0 ? x / n - 1 : x / n);
		x -= (div * n);
		x += ((x - 1) * (m - 1));
		x += div;
		cout << x << '\n';
	}
	return 0;
}
