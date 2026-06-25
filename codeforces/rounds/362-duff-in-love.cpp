/*
 * Duff in Love  [588B]
 * Problem:  https://codeforces.com/problemset/problem/588/B
 * Verdict:  ACCEPTED        Solved: 2021-04-03
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 0 KB
 * Tags:     math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/588/submission/111857857
 */

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) {
	return (b == 0 ? abs(a) : gcd(b, a % b));
}
set<ll> st;
void primeFactorize(ll x) {
	while (x % 2 == 0) {
		st.insert(2);
		x /= 2;
	}
	for (ll i = 3; i * i <= x; i+=2) {
		while (x % i == 0) {
			st.insert(i);
			x /= i;
		}
	}
	if (x > 2)st.insert(x);
}
int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	ll n;
	cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	primeFactorize(n);
	ll biggest = 1;
	for (auto& i : st) {
		biggest *= i;
	}
	cout << biggest;
	return 0;
}