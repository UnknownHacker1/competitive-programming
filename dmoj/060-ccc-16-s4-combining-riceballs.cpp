/*
 * CCC '16 S4 - Combining Riceballs  [ccc16s4]
 * Problem:  https://dmoj.ca/problem/ccc16s4
 * Verdict:  ACCEPTED (15.0 pts)   Solved: 2023-02-07
 * Language: C++20
 * Runtime:  0.740695205 s     Memory: 8508.0 KB
 * Source:   https://dmoj.ca/src/5296075
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
	int n;
	cin>>n;
	long long a[n];
	for(auto&i:a)cin>>i;
	long long dp[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			dp[i][j] = -1e18;
		}
	}
	map<long long, int> mp[405];
	for(int i = 0; i < n; i++){
		dp[i][i] = a[i];
		mp[i][a[i]] = i;
	}
	for(int x = 1; x < n; x++){
		for(int l = 0; l + x < n; l++){
			int r = l + x;
			for(int m1 = l; m1 < r; m1++){ 
				auto it = mp[r].find(dp[l][m1]);
				if(it == mp[r].end())
					continue;
				int m2 = it->second;
				if(m2 <= m1)continue; 
				if(l <= m1 && m1 < m2 && m2 <= r && dp[l][m1] == dp[m2][r]){
					dp[l][r]=max(dp[l][r],dp[l][m1] + (m1 + 1 > m2 - 1?0ll:dp[m1 + 1][m2 - 1]) + dp[m2][r]);
					mp[r][dp[l][r]] = l; 
				}
			}
		}
	}
	long long ans = 0;
	for(int l = 0; l < n; l++){
		for(int r = l; r < n; r++){
			ans = max(ans, dp[l][r]);
		}
	}
	cout<<ans;
}