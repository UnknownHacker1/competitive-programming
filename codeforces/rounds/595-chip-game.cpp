/*
 * Chip Game  [1719A]
 * Problem:  https://codeforces.com/problemset/problem/1719/A
 * Verdict:  ACCEPTED        Solved: 2022-08-16
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     games, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1719/submission/168516763
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
	int n,m;
	cin>>n>>m;
	if(n%2==m%2)
		cout<<"Tonya\n";
	else cout<<"Burenka\n";
}
}	
