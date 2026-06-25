/*
 * Elephant  [617A]
 * Problem:  https://codeforces.com/problemset/problem/617/A
 * Verdict:  ACCEPTED        Solved: 2020-08-04
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 3600 KB
 * Tags:     math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/617/submission/88895685
 */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	if(n<10)
	{
		if (n == 5) cout << 1;
		else cout << n / 5 + 1;
	}
	else
	{
		double d = n / 5;
		if (n % 5 == 0) goto out;
		if (round(d) >= d)
		{
			d += 0.5;
		}
	out:
		cout << round(d);
	}
	return 0;
}