/*
 * GlobeX Cup '19 J4 - Winni's Lonely Card Game  [globexcup19j4]
 * Problem:  https://dmoj.ca/problem/globexcup19j4
 * Verdict:  ACCEPTED (5.0 pts)   Solved: 2023-02-03
 * Language: C++20
 * Runtime:  1.082503428 s     Memory: 7204.0 KB
 * Source:   https://dmoj.ca/src/5280894
 */

// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <cstdint>
using namespace std; 
int main() {
	int n, m, k;
	cin>>n>>m>>k;
	int a[n];
	map<int,int>freq{};
	for(int i = 0; i < n; i++){
		cin>>a[i];
		freq[a[i]]++;
	}
	sort(a,a+n,[&](int aa, int bb){
		return freq[aa]>freq[bb];
	});
	long long ans = 0;
	for(int i = 0; i < n; i++){ 
		long long take = min(k, freq[a[i]]);
		k -= take;
		freq[a[i]] -= take;
		ans += take * (take - 1) / 2;
	}
	cout<<ans;
}