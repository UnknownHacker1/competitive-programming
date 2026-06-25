/*
 * In-game Chat  [1411A]
 * Problem:  https://codeforces.com/problemset/problem/1411/A
 * Verdict:  ACCEPTED        Solved: 2021-04-14
 * Language: C++17 (GCC 7-32)
 * Runtime:  30 ms     Memory: 0 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1411/submission/113013595
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
		string s;
		cin >> s;
		int cnt = 0,i=n-1;
		while (i >= 0 && s[i--] == ')')++cnt;
		if (cnt > n - cnt) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}