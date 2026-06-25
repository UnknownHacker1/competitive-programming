/*
 * Median on Segments (Permutations Edition)  [1005E1]
 * Problem:  https://codeforces.com/problemset/problem/1005/E1
 * Verdict:  ACCEPTED        Solved: 2022-07-08
 * Language: C++20 (GCC 11-64)
 * Runtime:  78 ms     Memory: 10300 KB
 * Tags:     sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1005/submission/163316520
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
	int n,m;
	cin>>n>>m;
	int p[n];
	for(auto&i:p)cin>>i;
	map<int,int>freq{};
	int x=0;	
	for(int i = find(p,p+n,m)-p; i < n; i++){
		if(p[i]>m)x++;
		else if(p[i]<m) x--;
		freq[x]++;
	}
	x=0;
	ll ans=0;
	for(int i = find(p,p+n,m)-p; i >= 0; i--){
		if(p[i]>m)x++;
		else if(p[i]<m) x--;
		ans+=freq[-x]+freq[1-x];
	}
	cout<<ans;
}
