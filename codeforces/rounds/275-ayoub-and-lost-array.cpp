/*
 * Ayoub and Lost Array  [1105C]
 * Problem:  https://codeforces.com/problemset/problem/1105/C
 * Verdict:  ACCEPTED        Solved: 2022-08-13
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 4700 KB
 * Tags:     combinatorics, dp, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1105/submission/168204566
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
ll n;
ll dp[(int)2e5+5][3];
ll mod = 1e9+7;
ll c[3];
int main()
{
	ACPLS();
	ll l,r;
	cin>>n>>l>>r;
	for(int i = 0; i < 3; i++){
		ll cpl=l,cpr=r;
		while(cpl % 3 != i)++cpl;
		while(cpr % 3 != i && cpr >= cpl){
			--cpr;
			if(cpr == 0)break;
		}
		c[i] = cpr < cpl ? 0ll : (cpr - cpl) / 3 + 1;
		dp[0][i]=c[i];
	}
	for(int i = 1; i < n; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				dp[i][j]+=dp[i-1][k] * c[(j-k+3)%3];
				dp[i][j]%=mod;
			}
		}
	}
	cout<<dp[n-1][0];
}	
