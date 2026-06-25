/*
 * Credit Card  [893D]
 * Problem:  https://codeforces.com/problemset/problem/893/D
 * Verdict:  ACCEPTED        Solved: 2022-08-19
 * Language: C++20 (GCC 11-64)
 * Runtime:  31 ms     Memory: 2400 KB
 * Tags:     data structures, dp, greedy, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/893/submission/168905620
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
	ll n,d;
	cin>>n>>d;
	ll a[n],p[n];
	for(int i = 0; i < n; i++){
		cin>>a[i];
		p[i]=a[i];
		if(i)p[i]+=p[i-1];
	}
	ll max_suff[n];
	max_suff[n-1] = p[n-1];
	for(int i = n-2; i >= 0; i--){
		max_suff[i]=max(max_suff[i+1],p[i]);
	}
	ll added = 0, ans = 0, cnt =  0;
	for(int i = 0; i < n; i++){ 
		if(p[i]+added>d){
			ans=-1;
			break;
		}
		if(a[i]||p[i]+added>=0)continue;
		ll x = max(0ll, d - max_suff[i] - added);
		added += x;
		ans++;
		if(p[i] + added < 0){
			ans = -1;
			break;
		}
		if(p[i]+added>d){
			ans=-1;
			break;
		}
	}
	cout<<ans;
}	
