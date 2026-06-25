/*
 * Fox Dividing Cheese  [371B]
 * Problem:  https://codeforces.com/problemset/problem/371/B
 * Verdict:  ACCEPTED        Solved: 2021-04-03
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 0 KB
 * Tags:     math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/371/submission/111855567
 */

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) {
	return (b == 0 ? abs(a) : gcd(b, a % b));
}
ll cntdiv(ll& x, ll y) {
	ll cnt = 0;
	while (x % y == 0) {
		cnt++;
		x /= y;
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	ll a, b;
	cin >> a >> b;
	ll _gcd = gcd(a, b);
	a /= _gcd;
	b /= _gcd;
	int ans = 0;
	ans = cntdiv(a, 2) + cntdiv(a, 3) + cntdiv(a, 5) + cntdiv(b, 2) + cntdiv(b, 3) + cntdiv(b, 5);
	if (a == b)
		cout << ans;
	else cout << -1;
	return 0;
}