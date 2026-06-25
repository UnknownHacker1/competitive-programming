/*
 * Maximum Distributed Tree  [1401D]
 * Problem:  https://codeforces.com/problemset/problem/1401/D
 * Verdict:  ACCEPTED        Solved: 2022-07-26
 * Language: C++20 (GCC 11-64)
 * Runtime:  62 ms     Memory: 17100 KB
 * Tags:     dfs and similar, dp, greedy, implementation, math, number theory, sortings, trees
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1401/submission/165834158
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
#define tc         \
    int tttttt,subtask;    \
    cin >> tttttt /*>> subtask*/; \
    while (tttttt--)
#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end()
ll sub[(int)1e5+3];
vector<int>adj[(int)1e5+3];
int par[(int)1e5+3];
int n;
vector<ll>v;
ll mod = 1e9+7;
int dfs(int node, int prev){
	int ret = 1;
	for(int ch:adj[node]){
		if(ch==prev)continue;
		par[ch]=node;
		ret+=dfs(ch,node);
	}
	if(prev!=-1)v.push_back(ret*1ll*(n-ret));
	return sub[node]=ret;
}
ll f(ll x, ll n){
	return x * (n - x);
}
ll f2(ll x, ll n){
	return (x%mod*(n-x)%mod)%mod;
}
int main()
{
	ACPLS();
tc{ 
	cin>>n;
	for(int i = 1; i <= n; i++){
		sub[i]=0;
		adj[i].clear();
		par[i]=0;
	}
	v.clear();
	for(int i = 1; i < n; i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,-1);
	sort(v.begin(),v.end());
	int m;
	cin>>m;
	ll p[m];
	for(ll&i:p)cin>>i; 
	sort(p,p+m); 
	ll ans = 0;
	while(m>n-1){
		p[n-2]*=p[m-1]; 
		p[n-2]%=mod;
		m--;
	}
	for(int i = n-2; i >= 0; i--){
		if(m==0){
			ans+=v[i];
			ans%=mod;
		}
		else{
			ans+=(v[i]%mod*p[m-1])%mod;
			ans%=mod;
			m--;
		}
	}
	cout<<ans<<'\n';
}
}
