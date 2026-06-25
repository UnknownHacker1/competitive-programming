/*
 * Chloe and the sequence   [743B]
 * Problem:  https://codeforces.com/problemset/problem/743/B
 * Verdict:  ACCEPTED        Solved: 2021-01-04
 * Language: C++17 (GCC 7-32)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     binary search, bitmasks, constructive algorithms, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/743/submission/103160296
 */

#include <bits/stdc++.h>
using namespace std;
// Important functions and defines
typedef long long ll;
#define f first
#define s second
ll POW(ll expo, ll power) {
    ll res = expo; if (!power) return 1; while (--power) res *= expo; return res;
}
ll sum_range2d(int i, int j, int k, int l, vector<vector<ll>>& s) {
    return s[k][l] - s[k][j - 1] - s[i - 1][l] + s[i - 1][j - 1];
}
ll gcd(ll a, ll b) {
    return (b == 0 ? abs(a) : gcd(b, a % b));
}
bool intersect(pair<int, int> p1, pair<int, int> p2) {
  int x1 = p1.first, x2 = p1.second, y1 = p2.first, y2 = p2.second;
  return (x1 >= y1 && x1 <= y2) ||
         (x2 >= y1 && x2 <= y2) ||
         (y1 >= x1 && y1 <= x2) ||
         (y2 >= x1 && y2 <= x2);
}
// End
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    ll n, k;
    cin>>n>>k;
    for(ll i = 3; i <= n; i++) {
        ll res = POW(2, i-1);
        if(k==res) {
            cout<<i;
            return 0;
        }
    }
    for(ll i = n; i >= 3; i--) {
        ll res = POW(2, i-1);
        if(k-res <= 0) continue;
        if((k-res)%(res*2)==0) {
            cout<<i;
            return 0;
        }
    }
    if(k%2) cout << 1;
    else cout << 2;
    return 0;
}