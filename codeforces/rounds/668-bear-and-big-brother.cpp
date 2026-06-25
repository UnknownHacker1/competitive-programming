/*
 * Bear and Big Brother  [791A]
 * Problem:  https://codeforces.com/problemset/problem/791/A
 * Verdict:  ACCEPTED        Solved: 2020-08-04
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 3700 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/791/submission/88885854
 */

#include <iostream>

using namespace std;

int main()
{
	int l, k;
	cin >> l >> k;
	int i = 1;
	for(; (k*=2) >= (l*=3); i++)
	{
		
	}
	cout << i;
	return 0;
}