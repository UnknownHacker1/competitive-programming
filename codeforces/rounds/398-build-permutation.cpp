/*
 * Build Permutation  [1713C]
 * Problem:  https://codeforces.com/problemset/problem/1713/C
 * Verdict:  ACCEPTED        Solved: 2022-08-06
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 400 KB
 * Tags:     constructive algorithms, dp, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1713/submission/167280984
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
	int p[n];
	for(int i = 0; i < n; i++)p[i]=i;
	for(int i = n-1; i >= 0; ){
		int j = i;
		while(j>=0&&int(sqrt(p[i]+j))!=sqrt(p[i]+j))j--;
		reverse(p+j,p+i+1);
		i=j-1;
	}
	bool ok = 1;
	for(int i = 0; i < n; i++){
		if(int(sqrt(p[i]+i))!=sqrt(p[i]+i))ok=0;
	}
	if(!ok)cout<<-1;
	else{
		for(int i : p)cout<<i<<' ';
	}
	cout<<'\n';
}
	return 0;
}	
