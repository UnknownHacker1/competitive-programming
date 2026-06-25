/*
 * Average Height  [1509A]
 * Problem:  https://codeforces.com/problemset/problem/1509/A
 * Verdict:  ACCEPTED        Solved: 2021-04-16
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 200 KB
 * Tags:     constructive algorithms
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1509/submission/113189927
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
		int n;
		cin >> n;
		vector<ll> a(n);
		for (auto& i : a)cin >> i;
		vector<ll>odds, evens;
		for (auto& i : a) {
			if (i & 1)odds.push_back(i);
			else evens.push_back(i);
		}
		for (auto& i : odds)cout << i << ' ';
		for (auto& i : evens)cout << i << ' ';
		cout << '\n';
	}
	return 0;
}