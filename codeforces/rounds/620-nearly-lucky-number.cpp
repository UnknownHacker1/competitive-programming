/*
 * Nearly Lucky Number  [110A]
 * Problem:  https://codeforces.com/problemset/problem/110/A
 * Verdict:  ACCEPTED        Solved: 2020-08-11
 * Language: C++17 (GCC 7-32)
 * Runtime:  92 ms     Memory: 3700 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/110/submission/89572771
 */

#include <iostream>
using namespace std;
#define ll long long

void test_case()
{
	ll n1;
	cin >> n1;
	int lucky_nums = 0;
	while (n1)
	{
		const int temp = n1 % 10;
		if (temp == 4 || temp == 7) ++lucky_nums;
		n1 /= 10;
	}
	if (lucky_nums == 4 || lucky_nums == 7)
	{
		cout << "YES";
	}
	else cout << "NO";
}

int main()
{
	test_case();
	return 0;
}
