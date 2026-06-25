/*
 * Beautiful Array  [1715B]
 * Problem:  https://codeforces.com/problemset/problem/1715/B
 * Verdict:  ACCEPTED        Solved: 2022-08-20
 * Language: C++20 (GCC 11-64)
 * Runtime:  31 ms     Memory: 2100 KB
 * Tags:     constructive algorithms, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1715/submission/169106789
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
int main()
{
	ACPLS();
tc{
	ll n,k,b,s;
	cin>>n>>k>>b>>s;
	vector<ll>ans;
	ll cnt = n;
	while(cnt>1 && s >= k-1 && s/k != b){
		cnt--;
		s -= (k-1);
		ans.push_back(k-1);
	}
	ans.push_back(s);
	while(ans.size()<n){
		ans.push_back(0);
	}
	if(s/k != b){
		cout<<"-1\n";
	}
	else{
		for(ll i:ans)cout<<i<<' ';
		cout<<'\n';
	}
}
}	
