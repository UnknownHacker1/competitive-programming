/*
 * Sum of Digits  [102B]
 * Problem:  https://codeforces.com/problemset/problem/102/B
 * Verdict:  ACCEPTED        Solved: 2020-12-30
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 300 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/102/submission/102757144
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
ll sod(ll n) {
    ll val = 0;
    while(n) {
        val+=n%10;
        n/=10;
    }
    return val;
}
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    string s;
    cin>>s;
    int ans = (s.size() >= 2);
    ll val = 0;
    for(int i = 0; i < (int)s.size(); i++) {
        val+=(s[i]-'0');
    }
    while(val >= 10) {
        val = sod(val);
        ++ans;
    }
    cout<<ans;
    return 0;
}
