/*
 * Box Fitting  [1498B]
 * Problem:  https://codeforces.com/problemset/problem/1498/B
 * Verdict:  ACCEPTED        Solved: 2021-04-07
 * Language: C++17 (GCC 7-32)
 * Runtime:  77 ms     Memory: 800 KB
 * Tags:     binary search, bitmasks, data structures, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1498/submission/112260780
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
	int tt;
	cin >> tt;
	while (tt--) {
		ll n, W, finished,ans=1;
		cin >> n >> W;
		ll curAv = W; finished = n;
		vector<ll> w(n), freq(23, 0);
		for (int i = 0; i < n; i++)
			cin >> w[i];
		for (int i = 0; i < n; i++)
			++freq[(ll)log2(w[i])];
		while(finished!=0) {
			ll mx=-1;
			for (ll x = 0; x <= 20; x++) {
				if (curAv >= (1ll << x) && freq[x]>0) {
					mx = max(mx, x);
				}
			}
			if (mx != -1) {
				curAv -= (1ll << mx);
				--finished;
				--freq[mx];
			}
			else {
				++ans;
				curAv = W;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}