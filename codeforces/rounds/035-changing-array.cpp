/*
 * Changing Array  [1054D]
 * Problem:  https://codeforces.com/problemset/problem/1054/D
 * Verdict:  ACCEPTED        Solved: 2022-08-14
 * Language: C++20 (GCC 11-64)
 * Runtime:  358 ms     Memory: 50200 KB
 * Tags:     greedy, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1054/submission/168285164
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void ACPLS()
{
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void moo(string fileName){
    freopen((fileName+".in").c_str(),"r",stdin);
    freopen((fileName+".out").c_str(),"w",stdout);
}
#define tc         \
    int tttttt,subtask;    \
    cin >> tttttt /*>> subtask*/; \
    while (tttttt--)
#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end()
int main()
{
	ACPLS();
	ll n, k;
	cin >> n >> k;
	map<ll, ll> freq{};
	ll ans =  n * (n+1) / 2;
	ll cur = 0, x;
	freq[0]=1;
	for(int i = 0; i < n; i++){
		cin>>x;
		cur^=x;
		freq[cur]++;
	}
	map<ll,bool>vis{};
	for(auto it:freq){
		if(vis[it.first])continue;
		vis[it.first] = 1;
		vis[((1ll<<k)-1) ^ it.first] = 1;
		ll a = (it.second + freq[((1ll<<k)-1) ^ it.first])/2;
		ll b = it.second + freq[((1ll<<k)-1) ^ it.first] - a;
		ans -= a * (a - 1) / 2;
		ans -= b * (b - 1) / 2;
	}
	cout<<ans;
}	
