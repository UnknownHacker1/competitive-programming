/*
 * Vanya and Fence  [677A]
 * Problem:  https://codeforces.com/problemset/problem/677/A
 * Verdict:  ACCEPTED        Solved: 2020-08-12
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 0 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/677/submission/89734373
 */

#include <iostream>
#include <vector>

using namespace std;
#define ll long long

void test_case()
{
 int friends_num, hf;
 cin>>friends_num>>hf;
 int min_wid = 0;
 for(int i = 0; i < friends_num; i++)
 {
  int num;
  cin>>num;
  num <= hf ? min_wid+=1 : min_wid+=2;
 }
 cout << min_wid;
}

int main()
{
    test_case();
    return 0;
}
