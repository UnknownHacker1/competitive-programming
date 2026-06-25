/*
 * Bit++  [282A]
 * Problem:  https://codeforces.com/problemset/problem/282/A
 * Verdict:  ACCEPTED        Solved: 2020-08-02
 * Language: C++17 (GCC 7-32)
 * Runtime:  46 ms     Memory: 3700 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/282/submission/88758604
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int x = 0;
	while(n--)
	{
		string op;
		cin >> op;
		if(op[0] == 'X')
		{
			if (op[1] == '+') x++;
			else x--;
		}
		else
		{
			if (op[0] == '+')
			{
				++x;
			}
			else --x;
		}
	}
	cout << x;
	return 0;
}