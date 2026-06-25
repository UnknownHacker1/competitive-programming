/*
 * Next Round  [158A]
 * Problem:  https://codeforces.com/problemset/problem/158/A
 * Verdict:  ACCEPTED        Solved: 2020-08-02
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 3700 KB
 * Tags:     *special, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/158/submission/88742431
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	size_t n;
	int k, k_value = -1, advanced = 0;
	cin >> n >> k;
	vector<int> vec(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> vec[i];
		if(i + 1 == k)
		{
			k_value = vec[i];
		}
	}
	if(k_value == -1)
	{
		cout << 0;
		return 0;
	}
	for(auto i : vec)
	{
		if (i < k_value) break;
		if (i >= k_value && i > 0) ++advanced;
	}
	cout << advanced;
	return 0;
}