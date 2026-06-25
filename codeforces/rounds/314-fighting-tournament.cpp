/*
 * Fighting Tournament  [1719C]
 * Problem:  https://codeforces.com/problemset/problem/1719/C
 * Verdict:  ACCEPTED        Solved: 2022-08-16
 * Language: C++20 (GCC 11-64)
 * Runtime:  46 ms     Memory: 3100 KB
 * Tags:     binary search, data structures, implementation, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1719/submission/168587680
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
	int n,q;
	cin>>n>>q;
	int a[n];
	for(int& i : a) cin >> i;
	int op = max(0, int(find(a,a+n,n) - a));
	int pos = find(a,a+n,n) - a;
	int i = 0, j = 1, r = 1, nxt = 2;
	vector<int>freq[n+1];
	while(op--){
		//cout<<i<<' '<<j<<'\n';
		if(a[i] > a[j]){
			freq[a[i]].push_back(r);
			j = nxt;
		}
		else{
			freq[a[j]].push_back(r);
			i = nxt; 
		}
		nxt++;
		r++;
	}
	//cout<<'\n';
	while(q--){
		int i,k;
		cin>>i>>k;
		--i;
		int ans = 0;
		auto it = upper_bound(freq[a[i]].begin(),freq[a[i]].end(),k);
		if(freq[a[i]].size() && it != freq[a[i]].begin()){
			ans += it - freq[a[i]].begin();
		}
		if(i == pos){
			ans += max(0, k - pos);
		}
		cout<<ans<<'\n';
	}
}
}	
