/*
 * There Are Two Types Of Burgers  [1207A]
 * Problem:  https://codeforces.com/problemset/problem/1207/A
 * Verdict:  ACCEPTED        Solved: 2021-04-15
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 0 KB
 * Tags:     brute force, greedy, implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1207/submission/113105156
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
ll pow(ll a, ll b) {
	ll res = 1;
	while (b--)res *= a;
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int tt = 1;
	cin >> tt;
	while (tt--) {
		int b, p, f, h, c;
		cin >> b >> p >> f >> h >> c;
		ll ans = 0;
		if (h > c) {
			while (b > 1 && p > 0)b -= 2, --p, ans+=h;
			while (b > 1 && f > 0)b -= 2, --f, ans+=c;
		}
		else {
			while (b > 1 && f > 0)b -= 2, --f, ans+=c;
			while (b > 1 && p > 0)b -= 2, --p, ans+=h;
		}
		cout << ans << '\n';
	}
	return 0;
}