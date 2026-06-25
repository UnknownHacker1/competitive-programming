/*
 * Omkar and Completion  [1372A]
 * Problem:  https://codeforces.com/problemset/problem/1372/A
 * Verdict:  ACCEPTED        Solved: 2022-07-10
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     constructive algorithms, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1372/submission/163591839
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
	while(n--)cout<<"1 ";
	cout<<'\n';
}
}
