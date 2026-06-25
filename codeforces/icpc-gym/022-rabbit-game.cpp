/*
 * Rabbit Game  [102873B]
 * Problem:  Gym/ICPC contest 102873 - problem B
 * Verdict:  ACCEPTED        Solved: 2020-11-25
 * Language: C++17 (GCC 7-32)
 * Runtime:  77 ms     Memory: 800 KB
 * Tags:     n/a
 * Author:   BidoTeima
 * Source:   https://codeforces.com/gym/102873/submission/99570839
 */

#include <bits/stdc++.h>
using namespace std;
// Important functions and defines
typedef long long ll;
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
    int r1 = 1, r2=0, n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 1; i < n; i++, r1 = i) {
        if(a[i] < a[i-1]) break;
    }
    if(r1==n) {cout<<n;return 0;}
    for(int i = n-1; i >= 1 && i != r1 && a[i-1] >= a[i]; i--, r2++) {
    }
    cout << r1 + r2 + 1;
    return 0;
}
