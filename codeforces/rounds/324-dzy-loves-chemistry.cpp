/*
 * DZY Loves Chemistry  [445B]
 * Problem:  https://codeforces.com/problemset/problem/445/B
 * Verdict:  ACCEPTED        Solved: 2021-04-06
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 200 KB
 * Tags:     dfs and similar, dsu, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/445/submission/112178885
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
vector<vector<int>> adj(53);
vector<bool> vis(53, 0);
ll sz = 0;
void dfs(int v) {
	if (vis[v])return;
	vis[v] = 1;
	++sz;
	for (auto& u : adj[v])
		dfs(u);
}
int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n, m, x, y;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (adj[i].size()) {
			dfs(i);
		}
		if (sz > 0)ans += sz - 1;
		sz = 0;
	}
	cout << (1ll << ans);
	return 0;
}