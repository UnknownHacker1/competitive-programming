/*
 * Review Site  [1511A]
 * Problem:  https://codeforces.com/problemset/problem/1511/A
 * Verdict:  ACCEPTED        Solved: 2021-04-12
 * Language: C++17 (GCC 7-32)
 * Runtime:  77 ms     Memory: 100 KB
 * Tags:     greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1511/submission/112792528
 */

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ld = long double;
#define MOD ll(1e9+7)
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
	int tt = 1;
	cin >> tt;
	for(int ttt = 1; ttt <= tt; ttt++) {
		ll upvotes = 0;
		int n;
		cin >> n;
		vector<ll> a(n);
		for (auto& i : a)cin >> i;
		for (auto& i : a) {
			if (i == 1 || i == 3)upvotes++;
		}
		cout << upvotes << '\n';
	}
	return 0;
}