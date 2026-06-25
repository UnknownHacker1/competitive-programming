/*
 * Anton and Danik  [734A]
 * Problem:  https://codeforces.com/problemset/problem/734/A
 * Verdict:  ACCEPTED        Solved: 2020-08-11
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 3900 KB
 * Tags:     implementation, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/734/submission/89575265
 */

#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

void test_case()
{
	string s;
	cin >> s;
	cin >> s;
	unsigned d = 0;
	unsigned a = 0;
	for (const auto& x : s)
	{
		if (x == 'A') ++a;
		else ++d;
		if (d > s.length() / 2)
		{
			cout << "Danik";
			exit(0);
		}
		if (a > s.length() / 2)
		{
			cout << "Anton";
			exit(0);
		}
	}
	if (a == d)
	{
		cout << "Friendship";
	}
	else if (a > d)
	{
		cout << "Antonio";
	}
	else if(d > a)
	{
		cout << "Danik";
	}
}
int main()
{
	test_case();
	return 0;
}
