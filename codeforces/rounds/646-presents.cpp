/*
 * Presents  [136A]
 * Problem:  https://codeforces.com/problemset/problem/136/A
 * Verdict:  ACCEPTED        Solved: 2020-08-12
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 0 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/136/submission/89731904
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    size_t n;
    cin>>n;
    vector<int> p(n);
    for(int i = 0; i < n; i++)
    {
     int temp;
     cin>>temp;
     p[temp-1] = i+1;
    }
    for(auto x : p)
    {
     cout << x << ' ';
    }
    return 0;
}
