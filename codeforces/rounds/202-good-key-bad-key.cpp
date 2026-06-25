/*
 * Good Key, Bad Key  [1703G]
 * Problem:  https://codeforces.com/problemset/problem/1703/G
 * Verdict:  ACCEPTED        Solved: 2022-07-12
 * Language: C++20 (GCC 11-64)
 * Runtime:  140 ms     Memory: 36800 KB
 * Tags:     bitmasks, brute force, dp, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1703/submission/163944119
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[(int)1e5+3][32];
ll a[(int)1e5+3];
int n,k;
ll rec(int idx, int div){
	if(idx==n)
		return 0;
	if(dp[idx][div]!=-1)
		return dp[idx][div];
	return dp[idx][div]=max(rec(idx+1,min(div+1,30))+(a[idx])/(1ll<<min(div+1,30)),
			   rec(idx+1,div)+(a[idx]/(1ll<<div))-k);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k; 
		for(int i = 0; i < n; i++)
			cin>>a[i];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 32; j++){
				dp[i][j]=-1;
			}
		}
		cout<<rec(0,0)<<'\n';
	}
}