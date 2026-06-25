/*
 * Helpful Maths  [339A]
 * Problem:  https://codeforces.com/problemset/problem/339/A
 * Verdict:  ACCEPTED        Solved: 2020-08-03
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 3700 KB
 * Tags:     greedy, implementation, sortings, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/339/submission/88765261
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string temp;
	cin >> temp;
	vector<int> nums;
	for(auto ch : temp)
	{
		if(ch!='+')
		 nums.push_back(ch - '0');
	}
	sort(nums.begin(), nums.end());
	for(size_t i = 0; i < nums.size(); i++)
	{
		if(i == nums.size()-1)
		{
			cout << nums[i];
			break;
		}
		cout << nums[i] << '+';
	}
	return 0;
}