/*
 * Boy or Girl  [236A]
 * Problem:  https://codeforces.com/problemset/problem/236/A
 * Verdict:  ACCEPTED        Solved: 2020-08-03
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 3700 KB
 * Tags:     brute force, implementation, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/236/submission/88794159
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int dist = 0;
	for(size_t i = 0; i < str.size(); i++)
	{
		if(str.find(str[i], i+1) == std::string::npos)
		{
			++dist;
		}
	}
	if (dist % 2 == 0) cout << "CHAT WITH HER!";
	else cout << "IGNORE HIM!";
	return 0;
}