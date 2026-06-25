/*
 * k-LCM (easy version)  [1497C1]
 * Problem:  https://codeforces.com/problemset/problem/1497/C1
 * Verdict:  ACCEPTED        Solved: 2021-03-17
 * Language: C++17 (GCC 7-32)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     constructive algorithms, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1497/submission/110225159
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
		ll n, k;
		cin >> n >> k;
		if (n % 4 == 0 && n > 4) {
			//cout << "case 1\n";
			cout << (n / 4) << ' ' << (n / 4) << ' ' << n / 2 << '\n';
		}
		else if (n % 2 == 0) {
			//cout << "case 2\n";
			cout << (n / 2) - 1 << ' ' << (n / 2) - 1 << ' ' << 2 << '\n';
		}
		else {
			//cout << "case 3\n";
			cout << n / 2 << ' ' << n / 2 << ' ' << 1 << '\n';
		}
	}
    return 0;
}
