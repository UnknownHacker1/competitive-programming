/*
 * Quiz Master  [1777C]
 * Problem:  https://codeforces.com/problemset/problem/1777/C
 * Verdict:  ACCEPTED        Solved: 2023-03-07
 * Language: C++20 (GCC 11-64)
 * Runtime:  358 ms     Memory: 800 KB
 * Tags:     binary search, math, number theory, sortings, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1777/submission/196389658
 */

// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int test;
	cin>>test;
	while(test--){
		int n,m;
		cin>>n>>m;
		int a[n];
		for(auto&i:a)cin>>i;
		sort(a,a+n);
		int j = -1;
		int cnt = 0;
		vector<int>vis(m + 1, 0);
		int ans = 1e9;
		for(int i = 0; i < n; i++){
			while(j + 1 < n && cnt < m){
				++j;
				for(int x = 1; x * x <= a[j]; x++){
					if(a[j] % x != 0)continue;
					if(x <= m && vis[x] == 0){
						++cnt;
					}
					if(x<=m)++vis[x];
					if(x * x == a[j])continue;
					if(a[j] / x <= m && vis[a[j] / x] == 0){
						++cnt;
					}
					if(a[j]/x<=m)++vis[a[j]/x];
				}
			}
			if(cnt >= m){
				ans = min(ans, a[j] - a[i]);
			}
			for(int x = 1; x * x <= a[i]; x++){
					if(a[i] % x != 0)continue;
					if(x <= m && vis[x] == 1){
						--cnt;
					}
					if(x<=m)--vis[x];
					if(x * x == a[i])continue;
					if(a[i] / x <= m && vis[a[i] / x] == 1){
						--cnt;
					}
					if(a[i]/x<=m)--vis[a[i]/x];
			}
		}
		cout<<(ans==1e9?-1:ans)<<'\n';
	}
}