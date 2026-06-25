/*
 * Omkar and Last Class of Math  [1372B]
 * Problem:  https://codeforces.com/problemset/problem/1372/B
 * Verdict:  ACCEPTED        Solved: 2022-07-10
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     greedy, math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1372/submission/163592777
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
	ll a = 1, b = n-1;
	for(ll i = 2; i * i <= n; i++){
		if(n%i==0){
			if(max(a,b)>max(max(i,n/i),n-max(i,n/i)))
				a=max(i,n/i),b=n-a;
		}
	}
	cout<<a<<' '<<b<<'\n';
}
}
