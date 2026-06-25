/*
 * Hulk  [705A]
 * Problem:  https://codeforces.com/problemset/problem/705/A
 * Verdict:  ACCEPTED        Solved: 2020-08-20
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 0 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/705/submission/90492318
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case()
{
 int n;
 cin>>n;
 for(int i = 1; i <= n; i++)
 {
	if(i>1) cout << "	that ";
	if(i % 2)
	{
		cout << "I hate ";
    }
    else cout << "I love "; 
 }
 cout << "it";
}
int main()
{
    test_case();	
	return 0;
}
