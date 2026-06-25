/*
 * Three swimmers  [1492A]
 * Problem:  https://codeforces.com/problemset/problem/1492/A
 * Verdict:  ACCEPTED        Solved: 2021-02-23
 * Language: C++17 (GCC 7-32)
 * Runtime:  30 ms     Memory: 0 KB
 * Tags:     math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1492/submission/108310888
 */

#include "bits/stdc++.h"
using ll = long long;
using namespace std;
int p,ans;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        ll p, a, b, c;
        cin >> p >> a >> b >> c;
        //cout << p % a << ' ' << p % b << ' ' << p % c << '\n';
        a *= ((p / a) + (p%a?1:0));
        b *= ((p / b) + (p%b?1:0));
        c *= ((p / c) + (p%c?1:0));
        //cout << a << ' ' << b << ' ' << c << '\n';
        cout << min({ a - p,b - p,c - p }) << '\n';
    }
    return 0;
}