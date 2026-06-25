/*
 * Beautiful Year  [271A]
 * Problem:  https://codeforces.com/problemset/problem/271/A
 * Verdict:  ACCEPTED        Solved: 2020-08-11
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 3800 KB
 * Tags:     brute force
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/271/submission/89581754
 */

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long

class IntsArray
{
private:
	int* array_ = nullptr;
	size_t size_ = 0;
public:
	IntsArray(int n)
	{
		size_ = static_cast<unsigned>(trunc(log10(n))) + 1;
		array_ = new int[size_];
		for (size_t i = 0; n; i++)
		{
			int temp = n % 10;
			array_[i] = temp;
			n /= 10;
		}
	}
	int toInt()
	{
		int x = 0;
		for (size_t i = 0; i < size_; i++)
		{
			x *= 10;
			x += array_[i];
		}
		return x;
	}
	int& operator[](size_t index)
	{
		return array_[index];
	}
	int* begin()
	{
		return &array_[0];
	}
	int* end()
	{
		return &array_[size_];
	}
	size_t size() { return size_; }
};

void test_case()
{
	int year;
	cin >> year;
	while (++year)
	{
		IntsArray num(year);
		bool dist = true;
		for (size_t i = 0; i < num.size(); i++)
		{
			if(find(num.begin()+i+1, num.end(), num[i]) != num.end())
			{
				dist = false;
				break;
			}
		}
		if(dist)
		{
			cout << year;
			break;
		}
	}
}
int main()
{
	test_case();
	return 0;
}
