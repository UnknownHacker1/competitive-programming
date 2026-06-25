/*
 * Way Too Long Words  [71A]
 * Problem:  https://codeforces.com/problemset/problem/71/A
 * Verdict:  ACCEPTED        Solved: 2020-08-02
 * Language: C++17 (GCC 7-32)
 * Runtime:  46 ms     Memory: 3600 KB
 * Tags:     strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/71/submission/88734166
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		if (str.length() > 10)
			cout << str[0] << str.length() - 2 << str[str.length() - 1] << endl;
		else cout << str << endl;
	}
	return 0;
}