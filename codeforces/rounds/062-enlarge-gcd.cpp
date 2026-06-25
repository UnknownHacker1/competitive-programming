/*
 * Enlarge GCD  [1034A]
 * Problem:  https://codeforces.com/problemset/problem/1034/A
 * Verdict:  ACCEPTED        Solved: 2022-07-08
 * Language: C++20 (GCC 11-64)
 * Runtime:  873 ms     Memory: 111200 KB
 * Tags:     number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1034/submission/163322295
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
vector<int>primes;
bool prime[(int)2e7+1];
int freq[(int)2e7+1];
void sieve(){
	memset(prime,1,sizeof(prime));
	for(ll i = 2; i <= 2e7; i++){
		if(prime[i]){
			primes.push_back(i);
			for(ll j = i * i; j <= 2e7; j+=i){
				prime[j]=0;
			}
		}
	}
}
int main()
{
	ACPLS();
	sieve();
	int n;
	cin>>n;
	int g = 0,mn=1e9,mx=0;
	for(int i = 0; i < n; i++){
		int x;
		cin>>x;
		mn=min(mn,x);
		mx=max(mx,x);
		freq[x]++;
		g=__gcd(g,x);
	}
	if(mn==mx){
		cout<<-1;
		return 0;
	}
	int ans = n-1;
	for(ll p : primes){
		int x = 0;
		for(ll i = g*p; i <= 2e7; i+=g*p){
			x+=freq[i];
		}
		ans=min(ans,n-x);
	}
	cout<<ans;
}
