/*
 * Team  [231A]
 * Problem:  https://codeforces.com/problemset/problem/231/A
 * Verdict:  ACCEPTED        Solved: 2020-08-02
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 3700 KB
 * Tags:     brute force, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/231/submission/88734696
 */

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int problems = 0;
	for(int i = 0; i < n; i++)
	{
		bool x, y, z;
		cin >> x >> y >> z;
		if (x + y + z >= 2) ++problems;
	}
	cout << problems;
	return 0;
}