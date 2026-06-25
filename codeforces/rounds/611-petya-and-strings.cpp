/*
 * Petya and Strings  [112A]
 * Problem:  https://codeforces.com/problemset/problem/112/A
 * Verdict:  ACCEPTED        Solved: 2020-08-02
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 3700 KB
 * Tags:     implementation, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/112/submission/88763990
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string string1;
	string string2;
	cin >> string1;
	cin >> string2;
	transform(string1.begin(), string1.end(), string1.begin(),
		[](unsigned char c) { return tolower(c); });
	
	transform(string2.begin(), string2.end(), string2.begin(),
		[](unsigned char c) { return tolower(c); });
	
	if (string1 == string2) { cout << 0; }
	else if(lexicographical_compare(string1.begin(), string1.end(), string2.begin(), string2.end()))
	{
		cout << -1;
	}
	else
	{
		cout << 1;
	}
	return 0;
}