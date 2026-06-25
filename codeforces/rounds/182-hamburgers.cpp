/*
 * Hamburgers  [371C]
 * Problem:  https://codeforces.com/problemset/problem/371/C
 * Verdict:  ACCEPTED        Solved: 2021-04-06
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 0 KB
 * Tags:     binary search, brute force
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/371/submission/112147871
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
ll lcm(const vector<ll>& vc) {
	ll ans = vc[0];
	for (int i = 1; i < (int)vc.size(); i++) {
		ans = lcm(ans, vc[i]);
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	string s;
	ll nb, ns, nc, pb, ps, pc, r, cntb=0,cnts=0,cntc=0,ans=0;
	cin >> s >> nb >> ns >> nc >> pb >> ps >> pc >> r;
	for (auto& i : s) {
		cntb += (i == 'B');
		cnts += (i == 'S');
		cntc += (i == 'C');
	}
	while ((nb*bool(cntb))+(ns*bool(cnts))+(nc*bool(cntc))>0) {
		if (nb - cntb < 0) {
			ll need = pb*(cntb - nb);
			if (need > r)break;
			else r -= need, nb = cntb;
		}
		if (ns - cnts < 0) {
			ll need = ps * (cnts - ns);
			if (need > r)break;
			else r -= need, ns = cnts;
		}
		if (nc - cntc < 0) {
			ll need = pc * (cntc - nc);
			if (need > r)break;
			else r -= need, nc = cntc;
		}
		++ans;
		nb -= cntb, ns -= cnts, nc -= cntc;
	}
	pb *= cntb, ps *= cnts, pc *= cntc;
	ans += r / (pb + ps + pc);
	cout << ans;
	return 0;
}