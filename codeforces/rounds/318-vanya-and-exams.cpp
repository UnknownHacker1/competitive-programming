/*
 * Vanya and Exams  [492C]
 * Problem:  https://codeforces.com/problemset/problem/492/C
 * Verdict:  ACCEPTED        Solved: 2020-12-21
 * Language: C++17 (GCC 7-32)
 * Runtime:  78 ms     Memory: 1600 KB
 * Tags:     greedy, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/492/submission/101986298
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
bool cmp(pair<ll, ll>& p1, pair<ll, ll>& p2) {
    return p1.s < p2.s;
}
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    ll n, r, avg, sum=0;
    cin>>n>>r>>avg;
    ll reqSum = avg*n;
    pair<ll, ll> a[n];
    for(int i = 0; i < n; i++) cin>>a[i].f>>a[i].s, sum+=a[i].f;
    sort(a, a+n, cmp);
    ll essays = 0;
    if(sum>=reqSum) {
        cout<<0;
        return 0;
    }
    ll needed=reqSum-sum;
    for(int i = 0; i < n; i++) {
        ll canUse=r-a[i].f;
        if(canUse<needed) {
            needed-=canUse;
            essays+=canUse*a[i].s;
        }
        else {
            essays+=needed*a[i].s;
            break;
        }
    }
    cout<<essays;
    return 0;
}
