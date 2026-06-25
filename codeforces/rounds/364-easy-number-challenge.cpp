/*
 * Easy Number Challenge  [236B]
 * Problem:  https://codeforces.com/problemset/problem/236/B
 * Verdict:  ACCEPTED        Solved: 2021-04-02
 * Language: C++17 (GCC 7-32)
 * Runtime:  342 ms     Memory: 7800 KB
 * Tags:     implementation, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/236/submission/111787838
 */

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
ll MOD = (1 << 30);
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a, b, c;
	ll sum = 0;
	cin >> a >> b >> c;
	vector<ll> dp((int)1e6+2, -1);
	for (ll i = 1; i <= a; i++) {
		for (ll j = 1; j <= b; j++) {
			for (ll k = 1; k <= c; k++) { 
				ll prod = i * j * k;
				if (dp[prod] != -1) {
					sum = (sum + dp[prod])%MOD;
					continue;
				}
				ll ret = 0;
				for (ll x = 1; x * x <= prod; x++) {
					if (prod % x == 0) {
						if ((prod / x) == x)ret += 1;
						else ret += 2;
					}
				}
				dp[prod] = ret;
				sum = (sum + dp[prod]) % MOD;
			}
		}
	}
	cout << sum;
	return 0;
}
