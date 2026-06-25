/*
 * Calculating Function  [486A]
 * Problem:  https://codeforces.com/problemset/problem/486/A
 * Verdict:  ACCEPTED        Solved: 2020-08-13
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 300 KB
 * Tags:     implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/486/submission/89828169
 */

#include <iostream>
#include <cmath>
using namespace std;
#define ll long long

void test_case()
{
 ll n;
 cin>>n;
 if(n%2) 
 {
  cout << -(n/2+1);
 } 
 else cout << n/2;
}
int main()
{
	test_case();
}