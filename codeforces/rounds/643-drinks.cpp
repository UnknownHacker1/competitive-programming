/*
 * Drinks  [200B]
 * Problem:  https://codeforces.com/problemset/problem/200/B
 * Verdict:  ACCEPTED        Solved: 2020-08-13
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 0 KB
 * Tags:     implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/200/submission/89829628
 */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long

void test_case()
{ 
 double n;
 cin>>n;
 double orange_juice_total_percent = 0;
 for(int i = 0; i < n; i++)
 {
 	int temp;
 	cin>>temp;
 	orange_juice_total_percent+=temp;
 }
 cout << setprecision(12) << fixed << orange_juice_total_percent / n;
}
int main()
{
	test_case();
}