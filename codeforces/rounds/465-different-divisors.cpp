/*
 * Different Divisors  [1474B]
 * Problem:  https://codeforces.com/problemset/problem/1474/B
 * Verdict:  ACCEPTED        Solved: 2021-01-19
 * Language: C++17 (GCC 7-32)
 * Runtime:  46 ms     Memory: 200 KB
 * Tags:     binary search, constructive algorithms, greedy, math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1474/submission/104848871
 */


#include <iostream>
#include <vector>
 
using namespace std;
/// Just wanted to see tags of the problem lol
void solve()
{
    int x;
    cin >> x;
    vector<int> p;
    for (int i = x + 1; ; i++)
    {
        int t = 1;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                t = 0;
                break;
            }
        }
        if (t)
        {
            p.push_back(i);
            break;
        }
    }
    for (int i = p.back() + x; ; i++)
    {
        int t = 1;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                t = 0;
                break;
            }
        }
        if (t)
        {
            p.push_back(i);
            break;
        }
    }
    /// Just wanted to see tags of problem lol
    cout << min(1ll * p[0] * p[1], 1ll * p[0] * p[0] * p[0]) << "\n";
}
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
    /// Just wanted to see tags of problem lol
 
        solve();
    }
}
