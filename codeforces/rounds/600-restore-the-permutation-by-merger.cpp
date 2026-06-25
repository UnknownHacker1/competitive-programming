/*
 * Restore the Permutation by Merger  [1385B]
 * Problem:  https://codeforces.com/problemset/problem/1385/B
 * Verdict:  ACCEPTED        Solved: 2020-08-04
 * Language: C++17 (GCC 7-32)
 * Runtime:  46 ms     Memory: 3600 KB
 * Tags:     greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1385/submission/88905870
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		size_t length;
		cin >> length;
		length *= 2;
		vector<int> arr(length);
		for(size_t i = 0; i < length; i++) cin >> arr[i];
		vector<int> vec(length / 2);
		for(auto x = arr.begin(); x != arr.end(); ++x)
		{
			if(std::find(x+1, arr.end(), *x) != arr.end())
			{
				vec.push_back(*x);
			}
		}
		for(auto i : vec)
		{
			if (!i) continue;
			cout << i << ' ';
		}
		cout << endl;
	}
	return 0;
}