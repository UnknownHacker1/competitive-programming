/*
 * Decoding  [746B]
 * Problem:  https://codeforces.com/problemset/problem/746/B
 * Verdict:  ACCEPTED        Solved: 2020-12-31
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 0 KB
 * Tags:     implementation, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/746/submission/102916667
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
    int n;
    cin>>n;
    string s;
    cin>>s;
    string ans1, ans2;
    bool endturn = true;
    for(int i = n-1; i >= 0; i--) {
        if(endturn) {
            ans2+=s[i], endturn = false;
        }
        else {
            ans1+=s[i], endturn = true;
        }
    }
    reverse(ans2.begin(), ans2.end());
    cout<<ans1<<ans2;
    return 0;
}
