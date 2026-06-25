/*
 * Stones on the Table  [266A]
 * Problem:  https://codeforces.com/problemset/problem/266/A
 * Verdict:  ACCEPTED        Solved: 2020-08-03
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 3600 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/266/submission/88765673
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	size_t n;
	cin >> n;
	string str;
	cin >> str;
	int min = 0;
	for(size_t i = 0; i < str.size()-1; i++)
	{
		if(str[i]==str[i+1])
		{
			++min;
		}
	}
	cout << min;
	return 0;
}