/*
 * GCD Length  [1511B]
 * Problem:  https://codeforces.com/problemset/problem/1511/B
 * Verdict:  ACCEPTED        Solved: 2021-04-12
 * Language: C++17 (GCC 7-32)
 * Runtime:  30 ms     Memory: 0 KB
 * Tags:     constructive algorithms, math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1511/submission/112854558
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
	for(int ttt = 1; ttt <= tt; ttt++) {
		ll a, b, c;
		cin >> a >> b >> c;
					ll ansa = 0, ansb = 0;
					if (a > b)ansa = pow(10ll, c - 1);
					else ansb = pow(10ll, c - 1);
					cout << pow(10ll, a - 1) + ansa << ' ' << pow(10ll, b - 1) + ansb << '\n';
	}
	return 0;
}