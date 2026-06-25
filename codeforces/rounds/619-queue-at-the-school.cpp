/*
 * Queue at the School  [266B]
 * Problem:  https://codeforces.com/problemset/problem/266/B
 * Verdict:  ACCEPTED        Solved: 2020-08-11
 * Language: C++17 (GCC 7-32)
 * Runtime:  92 ms     Memory: 3700 KB
 * Tags:     constructive algorithms, graph matchings, implementation, shortest paths
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/266/submission/89569571
 */

#include <iostream>
using namespace std;
#define ll long long

void test_case()
{
	int n;
	cin >> n >> n;
	string str;
	cin >> str;
	while (n--)
	{
		for (size_t i = 0; i < str.length() - 1; i++)
		{
			if (str[i] == 'B' && str[i + 1] == 'G')
			{
				swap(str[i], str[i + 1]);
				i++;
			}
		}
	}
	cout << str << endl;
}

int main()
{
	test_case();
}