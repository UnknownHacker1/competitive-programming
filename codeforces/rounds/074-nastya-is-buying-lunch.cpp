/*
 * Nastya Is Buying Lunch  [1136D]
 * Problem:  https://codeforces.com/problemset/problem/1136/D
 * Verdict:  ACCEPTED        Solved: 2022-07-25
 * Language: C++20 (GCC 11-64)
 * Runtime:  904 ms     Memory: 51700 KB
 * Tags:     greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1136/submission/165682968
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
int main()
{
	ACPLS();
	int n,m;
	cin>>n>>m;
 	bool hug[n+1]={0};
	int p[n+1];
	for(int i = 1; i <= n; i++){
		cin>>p[i];
	}
	map<pair<int,int>,bool>adj{};
	for(int i = 0; i < m; i++){
		int u,v;
		cin>>u>>v;
		if(v==p[n])hug[u]=1;
		adj[{u,v}]=1;
	}
	for(int i = n-2; i >= 1; i--){
		if(!hug[p[i]])continue;
		int j = i+1;
		while(j<n&&adj[{p[j-1],p[j]}]){
			swap(p[j-1],p[j]);
			j++;
		}
	}
	int ans=0;
	for(int i = n-1; i >= 1 && hug[p[i]]; i--){
		ans++;
	}
	cout<<ans;
}
