/*
 * Word  [59A]
 * Problem:  https://codeforces.com/problemset/problem/59/A
 * Verdict:  ACCEPTED        Solved: 2020-08-11
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 3700 KB
 * Tags:     implementation, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/59/submission/89574201
 */

#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

void test_case()
{
	string s;
	cin >> s;
	auto i = [&s]()
	{
		unsigned j = 0;
		for (auto x : s) if (toupper(x) == x) ++j;
		return j;
	};
	if(i() > s.length() / 2)
	{
		transform(s.begin(), s.end(), s.begin(), 
		[](unsigned char c)
		{
				return toupper(c);
		});
	}
	else
	{
		transform(s.begin(), s.end(), s.begin(), 
		[](unsigned char c)
		{
			return tolower(c);
		});
	}
	cout << s;
}

int main()
{
	test_case();
	return 0;
}
