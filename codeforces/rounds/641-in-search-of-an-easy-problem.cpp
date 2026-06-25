/*
 * In Search of an Easy Problem  [1030A]
 * Problem:  https://codeforces.com/problemset/problem/1030/A
 * Verdict:  ACCEPTED        Solved: 2020-08-12
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 0 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1030/submission/89739493
 */

#include <iostream>
#include <vector>

using namespace std;
#define ll long long

void test_case()
{
 bool hard;
 int n;
 cin>>n;
 for(int i = 0; i < n; i++)
 {
  cin>>hard;
  if(hard) break;
 }
 cout << (hard?"HARD":"EASY");
}
int main()
{
    test_case();
    return 0;
}
