/*
 * Tram  [116A]
 * Problem:  https://codeforces.com/problemset/problem/116/A
 * Verdict:  ACCEPTED        Solved: 2020-08-03
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 3700 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/116/submission/88830945
 */

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int greatest = 0;
	int remain = 0;
	for(int i = 0; i < n; i++)
	{
		int left, entered;
		cin >> left >> entered;
		const auto x = remain + (entered - left);
		if(x > greatest)
		{
			greatest = x;
		}
		remain += entered - left;
	}
	cout << greatest;
	return 0;
}