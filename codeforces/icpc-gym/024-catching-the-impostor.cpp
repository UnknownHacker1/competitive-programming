/*
 * Catching the Impostor  [102873A]
 * Problem:  Gym/ICPC contest 102873 - problem A
 * Verdict:  ACCEPTED        Solved: 2020-11-25
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 200 KB
 * Tags:     n/a
 * Author:   BidoTeima
 * Source:   https://codeforces.com/gym/102873/submission/99569086
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
    int n, k;
    cin>>n>>k;
    set<int> s;
    for(int i = 0; i < k; i++) {
        int num;
        cin>>num;
        s.insert(num);
    }
    if((int)s.size() == n-1) cout << "YES";
    else cout << "NO";
    return 0;
}
