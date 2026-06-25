/*
 * Palindromic characteristics  [835D]
 * Problem:  https://codeforces.com/problemset/problem/835/D
 * Verdict:  ACCEPTED        Solved: 2022-08-16
 * Language: C++20 (GCC 11-64)
 * Runtime:  2885 ms     Memory: 85900 KB
 * Tags:     brute force, dp, hashing, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/835/submission/168500368
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
bitset<25000001> dp[14];
bitset<25000001> vis[14];
string s;
bool rec(int i, int j, int k){
	if(k == 1 && i > j)
		return 1;
	else if(k == 1 && i == j){
		return s[i] == s[j];
	} 
	else if(i >= j)
		return 0;
	if(vis[k][i*5000+j])
		return dp[k][i*5000+j];
	vis[k][i*5000+j]=1;
	if(k == 1){
		return dp[k][i*5000+j] = s[i] == s[j] && rec(i + 1, j - 1, 1);
	}
	int mid = (j - i + 1) / 2;
	return dp[k][i*5000+j] = rec(i, j, k-1) && rec(i, i+mid-1, k-1) && rec(j-mid+1, j, k-1);
}
int main()
{
	ACPLS(); 
	cin>>s;
	int ans[14]={0};
	for(int k = 1; k <= 13; k++){
		for(int i = 0; i < (int)s.size(); i++){
			for(int j = i; j < (int)s.size(); j++){
				ans[k]+=rec(i,j,k);
			}
		}
	}
	for(int i = 1; i <= min((int)s.size(),13); i++){
		cout<<ans[i]<<' ';
	}
	for(int i = 14; i <= int(s.size()); i++){
		cout<<"0 ";
	}
}	