/*
 * Domino piling  [50A]
 * Problem:  https://codeforces.com/problemset/problem/50/A
 * Verdict:  ACCEPTED        Solved: 2020-08-02
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 3700 KB
 * Tags:     greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/50/submission/88755980
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	cout << m * n / 2;
	return 0;
}