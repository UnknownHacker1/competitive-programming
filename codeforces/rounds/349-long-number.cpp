/*
 * Long Number  [1157B]
 * Problem:  https://codeforces.com/problemset/problem/1157/B
 * Verdict:  ACCEPTED        Solved: 2021-01-04
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 500 KB
 * Tags:     greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1157/submission/103160235
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
    int n;
    cin>>n;
    string a;
    cin>>a;
    int f[10];
    for(int i = 1; i <= 9; i++) cin>>f[i];
    int start = 0;
    for(int i = 0; i < (int)a.size(); i++, start = i) {
        if(f[a[i]-'0']>a[i]-'0') {
            start = i;
            break;
        }
    }
    for(int i = start; i < (int)a.size() && f[a[i]-'0']>=a[i]-'0'; i++) {
        if(f[a[i]-'0']<a[i]-'0') break;
        a[i] = static_cast<char>(f[a[i]-'0']+'0');
    }
    cout<<a;
    return 0;
}