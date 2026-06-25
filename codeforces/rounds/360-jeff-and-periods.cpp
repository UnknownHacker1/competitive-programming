/*
 * Jeff and Periods  [352B]
 * Problem:  https://codeforces.com/problemset/problem/352/B
 * Verdict:  ACCEPTED        Solved: 2021-04-02
 * Language: C++17 (GCC 7-32)
 * Runtime:  156 ms     Memory: 7800 KB
 * Tags:     implementation, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/352/submission/111774345
 */

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) {
	return (b == 0 ? abs(a) : gcd(b, a % b));
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	map<int, vector<ll>>posarr{};
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		posarr[x].push_back(i);
	}
	vector<pair<int,int>> ans;
	for (auto& i : posarr) {
		vector<ll>& vec = i.second;
		if (vec.size() == 1) {
			ans.push_back({ i.first,0 });
			continue;
		}
		ll dif = vec[1]-vec[0];
		bool f = true;
		for (int i = 2; i < (int)vec.size(); i++) {
			if (vec[i] - vec[i - 1] != dif) f = false;
		}
		if (f)ans.push_back({ i.first,dif });
	}
	cout << ans.size() << '\n';
	for (auto& i : ans) {
		cout << i.first << ' ' << i.second << '\n';
	}
	return 0;
}
