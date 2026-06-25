/*
 * Salem and Sticks   [1105A]
 * Problem:  https://codeforces.com/problemset/problem/1105/A
 * Verdict:  ACCEPTED        Solved: 2022-08-13
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     brute force, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1105/submission/168202316
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
	int n;
	cin>>n;
	int a[n];
	for(int&i:a)cin>>i;
	int ans = 1e9, t=1;
	for(int i = 1; i <= 100; i++){
		int res = 0;
		for(int x:a){
			res+=max(abs(i-x)-1,0);
		}
		if(res<ans){
			ans=res;
			t=i;
		}
	}
	cout<<t<<' '<<ans;
}	
