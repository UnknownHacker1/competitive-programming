/*
 * Bovine Dilemma  [1466A]
 * Problem:  https://codeforces.com/problemset/problem/1466/A
 * Verdict:  ACCEPTED        Solved: 2020-12-30
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 200 KB
 * Tags:     brute force, geometry, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1466/submission/102802899
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
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        double x[n+1];
        for(int i = 0; i < n; i++) {
            cin>>x[i];
        }
        map<string, bool> freq{};
        int ans = 0;
        for(int st = 0; st < n; st++) {
            for(int i = st; i < n; i++) {
            double v;
            v = double((0.5) * (x[i]-x[st]));
            if(!freq[to_string(v)]) {
                freq[to_string(v)] = true;
                if(v != 0) ++ans;
            }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
