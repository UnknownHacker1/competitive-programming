/*
 * Send Boxes to Alice (Easy Version)  [1254B1]
 * Problem:  https://codeforces.com/problemset/problem/1254/B1
 * Verdict:  ACCEPTED        Solved: 2022-07-07
 * Language: C++20 (GCC 11-64)
 * Runtime:  109 ms     Memory: 8100 KB
 * Tags:     constructive algorithms, greedy, math, number theory, ternary search, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1254/submission/163149428
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
	int n;
	cin>>n; 
	vector<int>pos;
	int s = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin>>x;
		if(x==1){
			s++;
			pos.push_back(i);
		}
	}
	ll ans = 1e18;
	for(int i = 2; i <= s; i++){
		if(s%i!=0)continue;
		vector<vector<int>>arr;
		for(int j = 0; j < s/i; j++){
			vector<int>lol;
			for(int k = i * j; k < i*(j+1); k++){
				lol.push_back(pos[k]);
			}
			arr.push_back(lol);
		}
		ll res = 0;
		for(int j = 0; j < (int)arr.size(); j++){
			int med = (int)arr[j].size()%2?\
			arr[j][(int)arr[j].size()/2]:\
			(arr[j][(int)arr[j].size()/2-1]+arr[j][(int)arr[j].size()/2])/2;
			for(int i:arr[j]){
				res+=abs(i-med);
			}
		}
		ans=min(ans,res);
	}
	cout<<(ans==1e18?-1:ans);
}
