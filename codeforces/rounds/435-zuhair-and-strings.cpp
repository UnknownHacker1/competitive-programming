/*
 * Zuhair and Strings  [1105B]
 * Problem:  https://codeforces.com/problemset/problem/1105/B
 * Verdict:  ACCEPTED        Solved: 2022-08-13
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 500 KB
 * Tags:     brute force, implementation, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1105/submission/168202810
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
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int f[26]={0};
	int cnt = 1;
	if(k==1){
		f[s[0]-'a']++;
	}
	for(int i = 1; i < n; i++){
		if(s[i]!=s[i-1]){
			cnt=1;
		}
		else cnt++;
		if(cnt%k==0){
			f[s[i]-'a']++;
		}
	}
	cout<<*max_element(f,f+26);
}	
