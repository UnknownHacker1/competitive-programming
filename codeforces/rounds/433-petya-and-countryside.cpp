/*
 * Petya and Countryside  [66B]
 * Problem:  https://codeforces.com/problemset/problem/66/B
 * Verdict:  ACCEPTED        Solved: 2020-12-23
 * Language: C++17 (GCC 7-32)
 * Runtime:  92 ms     Memory: 0 KB
 * Tags:     brute force, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/66/submission/102137471
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
    int a[n], max_cnt=1;
    for(int i = 0; i < n; i++) cin>>a[i];

    for(int i = 0; i < n; i++) {

        int cnt = 1, check = i-1, x=a[i];
        while(check >= 0 && a[check] <= x) x=a[check],--check, ++cnt;

        x=a[i];
        check=i+1;
        while(check < n && a[check] <= x) x=a[check], ++check, ++cnt;

        max_cnt=max(max_cnt, cnt);

    }
    cout<<max_cnt<<'\n';
    return 0;
}
