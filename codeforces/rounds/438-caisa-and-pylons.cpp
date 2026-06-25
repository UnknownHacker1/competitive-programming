/*
 * Caisa and Pylons  [463B]
 * Problem:  https://codeforces.com/problemset/problem/463/B
 * Verdict:  ACCEPTED        Solved: 2020-12-30
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 800 KB
 * Tags:     brute force, implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/463/submission/102754980
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
    ll h[n+1]; h[0] = 0;
    for(int i = 1; i <= n; i++) cin>>h[i];
    ll rem = INT_MAX, earned =0;
    for(int i = 0; i < n; i++) {
        if(h[i+1] > h[i]) {
            int x = h[i+1]-h[i];
            earned-=x;
            if(earned<0) rem-=abs(earned), earned = 0;
        }
        else earned+=h[i]-h[i+1];
    }
    cout<<INT_MAX-rem;
    return 0;
}
