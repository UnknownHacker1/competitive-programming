/*
 * Oath of the Night's Watch  [768A]
 * Problem:  https://codeforces.com/problemset/problem/768/A
 * Verdict:  ACCEPTED        Solved: 2022-08-19
 * Language: C++20 (GCC 11-64)
 * Runtime:  202 ms     Memory: 800 KB
 * Tags:     constructive algorithms, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/768/submission/168963311
 */

#include <bits/stdc++.h>

#define ll long long
#define ld long double
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll a[n+1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    ll answ = n-2;
    for (ll i = 2; i <= n-1; i++)
        if (a[i] != a[1]) break;
    else answ--;
    for (ll i = n-1; i >= 2; i--)
        if (a[i] != a[n]) break;
        else answ--;
    if (answ < 0) answ = 0;
    cout << answ << endl;
    return 0;
}
