/*
 * P=NP  [106251B]
 * Problem:  Gym/ICPC contest 106251 - problem B
 * Verdict:  ACCEPTED        Solved: 2026-06-20
 * Language: C++20 (GCC 13-64)
 * Runtime:  31 ms     Memory: 100 KB
 * Tags:     n/a
 * Author:   team "balls" (HossamIsmail, BidoTeima, a1abay)
 * Source:   https://codeforces.com/gym/106251/submission/379571881
 */

#include <bits/stdc++.h>
using namespace std;
const int sz = 8e3 + 2;

void solve()
{
    string a, b;
    cin >> a >> b;
    while(a.back() == b.back() && a.back() == 'N')
    {
        a.pop_back();
        b.pop_back();
    }
    if(a.back() == b.back() && count(a.begin(), a.end(), 'P') == count(b.begin(), b.end(), 'P'))
    {
        cout << "YES" << '\n';
    }
    else
    {
        cout << "NO" << '\n';
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
