/*
 * Translation  [41A]
 * Problem:  https://codeforces.com/problemset/problem/41/A
 * Verdict:  ACCEPTED        Solved: 2020-08-11
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 3700 KB
 * Tags:     implementation, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/41/submission/89574582
 */

#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

void test_case()
{
	string s;
	cin >> s;
	string s2;
	cin >> s2;
	reverse(s.begin(), s.end());
	if (s == s2)
	{
		cout << "YES";
	}
	else cout << "NO";
}

int main()
{
	test_case();
	return 0;
}
