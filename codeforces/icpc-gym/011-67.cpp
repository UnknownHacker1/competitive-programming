/*
 * 67  [106251E]
 * Problem:  Gym/ICPC contest 106251 - problem E
 * Verdict:  ACCEPTED        Solved: 2026-06-20
 * Language: C++20 (GCC 13-64)
 * Runtime:  109 ms     Memory: 2400 KB
 * Tags:     n/a
 * Author:   team "balls" (HossamIsmail, BidoTeima, a1abay)
 * Source:   https://codeforces.com/gym/106251/submission/379575854
 */

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz = 3e5 + 2;
int n, a[sz];

int ask(int i, int j)
{
    cout << "? " << i << ' ' << j << endl;
    int x;
    cin >> x;
    return x;
}

void solve()
{
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n - n % 3; i += 3)
    {
        int x = ask(i, i + 1);
        int y = ask(i + 1, i + 2);
        a[i + 1] = __gcd(x, y);
        a[i] = x / a[i + 1];
        a[i + 2] = y / a[i + 1];
    }
    if(n % 3 == 1)
    {
        int x = ask(n - 1, n);
        a[n] = x / a[n - 1];
    }
    if(n % 3 == 2)
    {
        int x = ask(n - 2, n - 1);
        a[n - 1] = x / a[n - 2];

        x = ask(n - 1, n);
        a[n] = x / a[n - 1];
    }
    cout << "! ";
    for(int i = 1; i <= n; i++)
    {
        cout << a[i] << ' ';
    } 
    cout << endl;
}

signed main() 
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
