/*
 * Insomnia cure  [148A]
 * Problem:  https://codeforces.com/problemset/problem/148/A
 * Verdict:  ACCEPTED        Solved: 2020-08-20
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 0 KB
 * Tags:     constructive algorithms, implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/148/submission/90492735
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case()
{
 int k, l, m, n, d;
 cin>>k>>l>>m>>n>>d;
 int res = 0;
 for(int i = 1; i <= d; i++)
 {
	 if(i%k == 0  || i % l == 0 || i % m == 0 || i % n == 0)
	 {
		 ++res;
	 }
 }
 cout << res;
}
int main()
{
    test_case();	
	return 0;
}
