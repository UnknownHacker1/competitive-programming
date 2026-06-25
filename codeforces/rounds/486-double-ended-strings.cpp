/*
 * Double-ended Strings  [1506C]
 * Problem:  https://codeforces.com/problemset/problem/1506/C
 * Verdict:  ACCEPTED        Solved: 2021-03-25
 * Language: C++17 (GCC 7-32)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     brute force, implementation, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1506/submission/110988920
 */

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tt = 1; 
	cin >> tt;
	while (tt--) {
		string a, b;
		cin >> a >> b;
		int mxcommon = 0;
		for (int i = 0; i < (int)a.size(); i++) {
			for (int j = 1; j+i <= a.size(); j++) {
				string sub = a.substr(i, j);
				if (b.find(sub) != string::npos) {
					mxcommon = max(mxcommon, (int)sub.length());
				}
			}
		}
		cout << (a.size()-mxcommon)+(b.size()-mxcommon) << '\n';
	}
	return 0;
}
