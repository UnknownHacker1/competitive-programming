/*
 * Mathematical Circus  [1719B]
 * Problem:  https://codeforces.com/problemset/problem/1719/B
 * Verdict:  ACCEPTED        Solved: 2022-08-16
 * Language: C++20 (GCC 11-64)
 * Runtime:  46 ms     Memory: 2100 KB
 * Tags:     constructive algorithms, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1719/submission/168545522
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
	ll n,k;
	cin>>n>>k;
	bool ok = 1;
	vector<pair<int,int>>v;
	for(ll i = 1; i+1 <= n; i+=2){
		if((i+k)*(i+1) % 4 == 0)
			v.push_back({i,i+1});
		else if((i+1+k)*i % 4 == 0){
			v.push_back({i+1,i});
		}
		else ok = 0;
	}
	if(ok){
		cout<<"YES\n";
		for(auto i:v)
			cout<<i.first<<' '<<i.second<<'\n';
	}
	else cout<<"NO\n";
}
}	
