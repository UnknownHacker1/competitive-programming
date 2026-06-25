/*
 * Optimal Reduction  [1713B]
 * Problem:  https://codeforces.com/problemset/problem/1713/B
 * Verdict:  ACCEPTED        Solved: 2022-08-06
 * Language: C++20 (GCC 11-64)
 * Runtime:  31 ms     Memory: 800 KB
 * Tags:     constructive algorithms, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1713/submission/167247480
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
	int a[n],b[n];
	for(int i = 0; i < n; i++){
		cin>>a[i];
		b[i]=a[i];
	} 
	sort(b,b+n);
	int i = -1, j = n; 
	bool ok = 1;
	for(int k = 0; k < n; k++){
		if(a[i+1]!=b[k]&&a[j-1]!=b[k]){
			ok=0;
		}
		else if(a[i+1]==b[k]){
			++i;
		}
		else{
			--j;
		}
	}
	cout<<(ok?"YES\n":"NO\n");
}
	return 0;
}	
