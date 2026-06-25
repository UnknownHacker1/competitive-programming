/*
 * Tetrahedron  [166E]
 * Problem:  https://codeforces.com/problemset/problem/166/E
 * Verdict:  ACCEPTED        Solved: 2021-02-21
 * Language: C++17 (GCC 7-32)
 * Runtime:  684 ms     Memory: 156600 KB
 * Tags:     dp, math, matrices
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/166/submission/108132146
 */

#include "bits/stdc++.h"
using namespace std;
using ll = long long; // respunsible prugramar
///  free eye torture
constexpr int mod = 1000000007; // respunsible prugramar
int main() {

	vector<ll> pw3(10000005);
	pw3[0] = 1;
	for (ll i = 1; i <= 10000000; i++) {
		pw3[i] = (pw3[i - 1] * 3)%mod;
	}
	vector<ll> dp(10000005);
	dp[1] = 0;
	dp[2] = 3; /// 3 ^ 1 - dp[1]
	//dp[3]=6 /// 3 ^ 2 - dp[2]
	//dp[4]=21 /// 3 ^ 3 - dp[3]
	for (ll i = 3; i <= 10000000; i++) {
		dp[i] = (pw3[i - 1] - dp[i - 1] + mod) % mod;
	}
	int n=0;
	cin >> n;
	cout << dp[n];
	return 0;
}