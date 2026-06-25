/*
 * Three Pairwise Maximums  [1385A]
 * Problem:  https://codeforces.com/problemset/problem/1385/A
 * Verdict:  ACCEPTED        Solved: 2020-08-04
 * Language: C++17 (GCC 7-32)
 * Runtime:  171 ms     Memory: 3600 KB
 * Tags:     math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1385/submission/88904366
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		if(x==y && y==z)
		{
			cout << "YES\n" << x << ' ' << y << ' ' << z << endl;
		}
		else
		{
			if (x == y && x > z)
			{
				cout << "YES\n" << x << ' ' << z << ' ' << 1 << endl;
			}
			else if (y == z && y > x)
			{
				cout << "YES\n" << y << ' ' << x << ' ' << 1 << endl;
			}
			else if (z == x && z > y)
			{
				cout << "YES\n" << z << ' ' << y << ' ' << 1 << endl;
			}
			else cout << "NO" << endl;
		}
	}
	return 0;
}