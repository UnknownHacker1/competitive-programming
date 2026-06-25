/*
 * Wrong Subtraction  [977A]
 * Problem:  https://codeforces.com/problemset/problem/977/A
 * Verdict:  ACCEPTED        Solved: 2020-08-04
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 3600 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/977/submission/88886793
 */

#include <iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> k >> n;
	while(n--)
	{
		if(k % 10)
		{
			k -= 1;
		}
		else
		{
			k /= 10;
		}
	}
	cout << k;
	return 0;
}