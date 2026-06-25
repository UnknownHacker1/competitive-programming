/*
 * Ladder  [279C]
 * Problem:  https://codeforces.com/problemset/problem/279/C
 * Verdict:  ACCEPTED        Solved: 2021-04-07
 * Language: C++17 (GCC 7-32)
 * Runtime:  218 ms     Memory: 3000 KB
 * Tags:     dp, implementation, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/279/submission/112208171
 */

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) {
	return (b == 0 ? abs(a) : gcd(b, a % b));
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for (auto& i : a)cin >> i;
	vector<int> cmp(n+3); cmp[1] = 0; 
	for (int i = 2; i <= n; i++) {
		if (a[i - 1] < a[i - 2])cmp[i] = 2;
		else if (a[i - 1] > a[i - 2])cmp[i] = 1;
		else cmp[i] = 0; // (equal)
	}
	vector<ll>pref(n + 3); pref[0] = 0;
	pref[1] = 0;
	int lastOne = 0;
	for (int i = 2; i <= n; i++) {
		pref[i] = pref[i - 1];
		if ((lastOne == 0&&cmp[i]!=0) || (cmp[i] != 0 && cmp[i] != lastOne))++pref[i];
		lastOne = (cmp[i] ? cmp[i] : lastOne);
	}
	//for (int i = 1; i <= n; i++)cout << cmp[i] << ' '; cout << '\n';
	//for (int i = 1; i <= n; i++)cout << pref[i] << ' '; cout << '\n';
	vector<int>uniquePos;
	for (int i = 1; i <= n; i++) {
		if (cmp[i])uniquePos.push_back(i);
	}
	while (m--) {
		int l, r;
		cin >> l >> r;
		if (r - l <= 1) { 
			cout << "Yes\n";
			continue;
		}
		auto it = lower_bound(uniquePos.begin(), uniquePos.end(), l + 1);
		if (pref[r] - pref[*it] <= 1) {
			if (pref[r] - pref[*it] <= 0) {
				cout << "Yes\n";
				continue;
			}
			if (it == uniquePos.end() || (*it) >= r || cmp[(*it)] == 1) {
				cout << "Yes\n";
				continue;
			}
		}
		cout << "No\n";
	}
	return 0;
}