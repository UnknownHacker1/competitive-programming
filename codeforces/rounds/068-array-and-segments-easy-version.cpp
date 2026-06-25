/*
 * Array and Segments (Easy version)  [1108E1]
 * Problem:  https://codeforces.com/problemset/problem/1108/E1
 * Verdict:  ACCEPTED        Solved: 2022-07-11
 * Language: C++20 (GCC 11-64)
 * Runtime:  93 ms     Memory: 100 KB
 * Tags:     brute force, greedy, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1108/submission/163717752
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
	vector<pair<int,int>>q;
	int a[n+1];
	for(int i = 1; i <= n; i++)cin>>a[i];
	for(int i = 0; i < m; i++){
		pair<int,int>rng;
		cin>>rng.first>>rng.second;
		q.push_back(rng);
	}
	int ans = 0;
	vector<int>res;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int lol = 0;
			vector<int>mby;
			for(int k = 0; k < m; k++){
				auto rng=q[k];
				if(rng.first <= i && i <= rng.second && 
					(j<rng.first||j>rng.second)){
					lol++;
					mby.push_back(k+1);
				}
			}
			if(a[j]-a[i]+lol>ans){
				ans=a[j]-a[i]+lol;
				res=mby;
			}
		}
	}
	cout<<ans<<'\n';
	cout<<(int)res.size()<<'\n';
	for(int i : res)cout<<i<<' ';
}
