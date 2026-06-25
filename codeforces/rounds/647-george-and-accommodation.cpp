/*
 * George and Accommodation  [467A]
 * Problem:  https://codeforces.com/problemset/problem/467/A
 * Verdict:  ACCEPTED        Solved: 2020-08-11
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 3600 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/467/submission/89576384
 */

#include <iostream>
using namespace std;
#define ll long long

void test_case()
{
	int n;
	cin >> n;
	unsigned rooms = 0;
	while(n--)
	{
		int q, p;
		cin >> p >> q;
		rooms += q - p >= 2;
	}
	cout << rooms;
}
int main()
{
	test_case();
	return 0;
}
