/*
 * Word Capitalization  [281A]
 * Problem:  https://codeforces.com/problemset/problem/281/A
 * Verdict:  ACCEPTED        Solved: 2020-08-03
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 3600 KB
 * Tags:     implementation, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/281/submission/88765485
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;
	str[0] = toupper(str[0]);
	cout << str;
	return 0;
}