/*
 * Crossmarket  [1715A]
 * Problem:  https://codeforces.com/problemset/problem/1715/A
 * Verdict:  ACCEPTED        Solved: 2022-08-20
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     constructive algorithms, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1715/submission/169094508
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
	if(n==1&&n==m)cout<<"0\n";
	else cout<<2*min(n,m)+max(n,m)-2<<'\n';
}
}	
