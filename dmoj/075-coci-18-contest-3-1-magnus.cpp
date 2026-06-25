/*
 * COCI '18 Contest 3 #1 Magnus  [coci18c3p1]
 * Problem:  https://dmoj.ca/problem/coci18c3p1
 * Verdict:  ACCEPTED (5.0 pts)   Solved: 2023-02-03
 * Language: C++20
 * Runtime:  0.165295948 s     Memory: 4056.0 KB
 * Source:   https://dmoj.ca/src/5280726
 */

// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
string word = "HONI";
int main() {
	string s;
	cin>>s;
	vector<int> occ[300];
	for(int i = 0; i < (int)s.size(); i++)occ[s[i]].push_back(i);
	int len = 0;
	int cur_idx = -1;
	for(int i = 0; ; i++){
		auto it = upper_bound(occ[word[i % 4]].begin(), occ[word[i % 4]].end(), cur_idx);
		if(it == occ[word[i % 4]].end()) break;
		cur_idx = *it; 
		len++;
	}
	cout<<len/4;
}