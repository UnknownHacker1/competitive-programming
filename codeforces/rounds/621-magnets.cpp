/*
 * Magnets  [344A]
 * Problem:  https://codeforces.com/problemset/problem/344/A
 * Verdict:  ACCEPTED        Solved: 2020-08-12
 * Language: C++17 (GCC 7-32)
 * Runtime:  218 ms     Memory: 0 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/344/submission/89739167
 */

#include <iostream>
#include <vector>

using namespace std;
#define ll long long

void test_case()
{
int past;
int next;
int n;
cin>>n;
int groups = 1;
cin>>past;
for(int i = 0; i < n-1; i++)
{
 cin>>next;
 groups+=past!=next;
 past=next;
}
cout<<groups;
}
int main()
{
    test_case();
    return 0;
}
