/*
 * Mind Control  [1291C]
 * Problem:  https://codeforces.com/problemset/problem/1291/C
 * Verdict:  ACCEPTED        Solved: 2021-09-11
 * Language: C++17 (GCC 7-32)
 * Runtime:  109 ms     Memory: 52000 KB
 * Tags:     brute force, data structures, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1291/submission/128510408
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void ACPLS(){
#ifndef ONLINE_JUDGE
	freopen("output.txt","w",stdout);
	freopen("input.txt","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
#define tc int tttttt;cin>>tttttt;while(tttttt--)
int n;
int a[3505];
int dp[3506][3506];
int rec(int l, int r, int cnt, int m){
	if(l+n-r==m)
		return max(a[l],a[r]);
	if(dp[l][r]!=-1)
		return dp[l][r];
	if(cnt>0){
		return dp[l][r]=max(rec(l+1,r,cnt-1,m),rec(l,r-1,cnt-1,m));
	}
	return dp[l][r]=min(rec(l+1,r,cnt,m),rec(l,r-1,cnt,m));
}
int main(){
    ACPLS();
tc{
	int m,k;
	cin>>n>>m>>k;
	for(int i = 0; i < n; i++)
		cin>>a[i];
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			dp[i][j]=-1;
		}
	}
	cout<<rec(0,n-1,k,m)<<'\n';
}
}