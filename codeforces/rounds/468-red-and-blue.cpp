/*
 * Red and Blue  [1469B]
 * Problem:  https://codeforces.com/problemset/problem/1469/B
 * Verdict:  ACCEPTED        Solved: 2020-12-28
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 0 KB
 * Tags:     dp, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1469/submission/102609609
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
    while(t--){
    int n;
    cin>>n;
    int r[n];
    for(int i = 0; i < n; i++) cin>>r[i];
    int m;
    cin>>m;
    int b[m];
    for(int i = 0; i < m; i++) cin>>b[i];
    int pfr[n+2]={0}, pfb[m+2]={0};
    pfr[1] = r[0];
    for(int i = 2; i <= n; i++) pfr[i] = r[i-1]+pfr[i-1];
    pfb[1] = b[0];
    for(int i = 2; i <= m; i++) pfb[i] = b[i-1]+pfb[i-1];
    int ans = 0;
    for(int r = 1; r <= n; r++) {
        for(int b = 1; b <= m; b++) {
            if(pfr[r]>ans) ans=pfr[r];
            if(pfb[b]+pfr[r]>ans) ans = pfb[b]+pfr[r];
            if(pfb[b]>ans) ans = pfb[b];
        }
    }
    cout<<ans<<'\n';
    }
    return 0;
}
