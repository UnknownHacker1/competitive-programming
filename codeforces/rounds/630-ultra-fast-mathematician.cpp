/*
 * Ultra-Fast Mathematician  [61A]
 * Problem:  https://codeforces.com/problemset/problem/61/A
 * Verdict:  ACCEPTED        Solved: 2020-08-13
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 200 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/61/submission/89828733
 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;
#define ll long long

void test_case()
{ 
 string s1;
 string s2;
 cin>>s1>>s2;
 string res;
 for(size_t i = 0; i < s1.length(); i++)
 {
  if(s1[i]==s2[i])
  {
  	res.push_back('0');
  }
  else res.push_back('1');
 }
 cout << res;
}
int main()
{
	test_case();
}