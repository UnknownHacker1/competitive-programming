/*
 * Traveling Salesman Problem  [1713A]
 * Problem:  https://codeforces.com/problemset/problem/1713/A
 * Verdict:  ACCEPTED        Solved: 2022-08-06
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     geometry, greedy, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1713/submission/167235458
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
tc{
	int n;
	cin>>n;
	int mxx=0,mnx=0,mxy=0,mny=0;
	for(int i = 0; i < n; i++){
		int x,y;
		cin>>x>>y;
		if(x==0)mxy=max(mxy,y),mny=min(mny,y);
		else mxx=max(mxx,x),mnx=min(mnx,x);
	}
	vector<int>v;
	v.push_back(mxx);
	v.push_back(abs(mnx));
	v.push_back(mxy);
	v.push_back(abs(mny));
	sort(v.begin(),v.end());
	cout<<2*(v[0]+v[1]+v[2]+v[3])<<'\n';
}
	return 0;
}	
