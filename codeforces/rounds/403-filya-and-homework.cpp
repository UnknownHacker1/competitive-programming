/*
 * Filya and Homework  [714B]
 * Problem:  https://codeforces.com/problemset/problem/714/B
 * Verdict:  ACCEPTED        Solved: 2021-03-04
 * Language: C++17 (GCC 7-32)
 * Runtime:  187 ms     Memory: 3300 KB
 * Tags:     implementation, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/714/submission/109113701
 */

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
set<ll> st;
ll vali(int i) {
	auto it = st.begin();
	while (i-- > 0) {
		++it;
	}
	//cout << *it << '\n';
	return *it;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll num;
		cin >> num;
		st.insert(num);
	}
	if (st.size() <= 2) {
		cout << "YES\n";
		return 0;
	}
	if (st.size() > 3) {
		cout << "NO\n";
		return 0;
	}

	bool yes = false;

	yes |= ( ((vali(2) - vali(0)) % 2 == 0) && vali(0) + ((vali(2) - vali(0)) / 2) == vali(1));
	yes |= ( ((vali(2) - vali(1)) % 2 == 0) && vali(1) + ((vali(2) - vali(1)) / 2) == vali(0));

	if (yes)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
