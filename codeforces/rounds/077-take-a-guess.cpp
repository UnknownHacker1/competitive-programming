/*
 * Take a Guess  [1556D]
 * Problem:  https://codeforces.com/problemset/problem/1556/D
 * Verdict:  ACCEPTED        Solved: 2022-07-09
 * Language: C++20 (GCC 11-64)
 * Runtime:  187 ms     Memory: 0 KB
 * Tags:     bitmasks, constructive algorithms, interactive, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1556/submission/163385080
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
int ask(int i, int j){
	cout<<"or "<<i<<' '<<j<<endl;
	int x;
	cin>>x;
	cout<<"and "<<i<<' '<<j<<endl;
	int y;
	cin>>y;
	return x+y;
}
int main()
{
	ACPLS();
	int n,k;
	cin>>n>>k;
	int a = ask(1,2),b=ask(2,3),c=ask(1,3);
	int arr[n+1];
	arr[1]=(a-b+c)/2;
	arr[2]=a-arr[1];
	arr[3]=b-arr[2];
	for(int i = 4; i <= n; i++){
		int x = ask(i-1,i);
		arr[i]=x-arr[i-1];
	}
	sort(arr+1,arr+n+1);
	cout<<"finish "<<arr[k]<<endl;
}
