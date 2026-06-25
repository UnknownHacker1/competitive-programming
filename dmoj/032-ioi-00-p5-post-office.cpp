/*
 * IOI '00 P5 - Post Office  [ioi00p5]
 * Problem:  https://dmoj.ca/problem/ioi00p5
 * Verdict:  ACCEPTED (15.0 pts)   Solved: 2023-02-04
 * Language: C++20
 * Runtime:  0.086119086 s     Memory: 3460.0 KB
 * Source:   https://dmoj.ca/src/5284171
 */

// Source: https://usaco.guide/general/io

#include <algorithm>
#include <bits/stdc++.h> 
using namespace std;
int prefix_sum[305];
int pos[305];
int v,p;
int range_sum(int l, int r){
	return prefix_sum[r] - (l == 0 ? 0 : prefix_sum[l - 1]);
}
int dp[305][35];
int rec(int idx, int rem){ 
	if(dp[idx][rem]!=-1)
		return dp[idx][rem];
	int ret = 1e9;
	for(int j = idx + 1; j <= v && rem; j++){
		// cover [idx, j] 
		int i = upper_bound(pos + idx, pos + j + 1, (pos[idx] + pos[j]) >> 1) - pos;
		// [idx, i - 1] -> i 
		// [i, j] -> j 
		int sum1 = range_sum(idx, i - 1) - (i - idx) * pos[idx];
		int sum2 = (j - i + 1) * pos[j] - range_sum(i, j); 
		ret = min(ret, rec(j, rem - 1) + sum1 + sum2);
	}
	return dp[idx][rem] = min(ret, range_sum(idx, v) - (v - idx + 1) * pos[idx]); 
}
void build(int idx, int rem){
	if(idx == v + 1)return;
	cout<<pos[idx]<<' ';
	int choice = idx + 1;
	int val = 1e9;
	for(int j = idx + 1; j <= v && rem; j++){
		int i = upper_bound(pos + idx, pos + j + 1, (pos[idx] + pos[j]) >> 1) - pos;
		int sum1 = range_sum(idx, i - 1) - (i - idx) * pos[idx];
		int sum2 = (j - i + 1) * pos[j] - range_sum(i, j);
		if(rec(j, rem - 1) + sum1 + sum2 < val){
			val = rec(j, rem - 1) + sum1 + sum2;
			choice = j;
		}
	}
	if(range_sum(idx, v) - (v - idx + 1) * pos[idx] < val){
		val = range_sum(idx, v) - (v - idx + 1) * pos[idx];
		choice = v + 1;
	}
	build(choice, rem - 1);
}
int main() {
	memset(dp,-1,sizeof(dp));
	cin>>v>>p;
	for(int i = 1; i <= v; i++)cin>>pos[i];
	prefix_sum[0] = 0;
	for(int i = 1; i <= v; i++){
		prefix_sum[i] = prefix_sum[i - 1] + pos[i]; 
	}
	int ans = 1e9;
	int choice = 1;
	for(int i = 1; i <= v; i++){ 
		if(rec(i, p - 1) + i * pos[i] - prefix_sum[i] < ans){
			ans = rec(i, p - 1) + i * pos[i] - prefix_sum[i];
			choice = i;
		}
	}
	cout<<ans<<'\n';
	build(choice, p - 1);
}