/*
 * Soldier and Bananas  [546A]
 * Problem:  https://codeforces.com/problemset/problem/546/A
 * Verdict:  ACCEPTED        Solved: 2020-08-03
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 3600 KB
 * Tags:     brute force, implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/546/submission/88828285
 */

#include <iostream>

using namespace std;

int main()
{
	int k, n, w;
	cin >> k >> n >> w;
	int price = 0;
	for(int i = k; i <= w*k; i+=k)
	{
		price += i;
	}
	cout << (price - n < 0? 0 : price - n);
	return 0;
}