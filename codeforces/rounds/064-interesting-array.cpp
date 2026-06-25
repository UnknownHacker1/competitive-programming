/*
 * Interesting Array  [482B]
 * Problem:  https://codeforces.com/problemset/problem/482/B
 * Verdict:  ACCEPTED        Solved: 2022-08-12
 * Language: C++20 (GCC 11-64)
 * Runtime:  93 ms     Memory: 13300 KB
 * Tags:     constructive algorithms, data structures, trees
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/482/submission/168023817
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
	int mx[n][30]={0};
	memset(mx,-1,sizeof(mx));
	int l[m],r[m],q[m];
	for(int i = 0; i < m; i++){
		cin>>l[i]>>r[i]>>q[i];
		--l[i],--r[i];
		for(int j = 0; j < 30; j++){
			if(q[i]&(1<<j)){
				mx[l[i]][j]=max(mx[l[i]][j],r[i]);
			}
		}
	}
	int a[n]={0};
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 30; j++){
			if(i)mx[i][j]=max(mx[i-1][j],mx[i][j]);
			if(mx[i][j]>=i)a[i]|=(1<<j);
		}
	}
	bool ok = 1;
	for(int i = 0; i < m; i++){
		int x = 0;
		for(int j = 0; j < 30; j++){
			if(mx[l[i]][j]>=r[i])x|=(1<<j);
		} 
		if(x!=q[i]){
			ok = 0;
			break;
		}
	}
	if(ok){
		cout<<"YES\n";
		for(int i:a)cout<<i<<' ';
	}
	else cout<<"NO";
}	
