/*
 * Last minute enhancements  [1466B]
 * Problem:  https://codeforces.com/problemset/problem/1466/B
 * Verdict:  ACCEPTED        Solved: 2020-12-30
 * Language: C++17 (GCC 7-32)
 * Runtime:  280 ms     Memory: 1400 KB
 * Tags:     dp, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1466/submission/102832471
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
        int x[n];
        for(int i = 0; i < n; i++) cin>>x[i];
        int freq[200005] = {0};
        for(int i = 0; i < n; i++) ++freq[x[i]];
        for(int i = n-1; i >= 0; i--) {
            if(freq[x[i]+1] == 0) {
                if(freq[x[i]] >= 1) --freq[x[i]];
                ++x[i], ++freq[x[i]];
            }
        }
        bool seen[200005] = {0};
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(!seen[x[i]]) {
                seen[x[i]] = true;
                ++ans;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
