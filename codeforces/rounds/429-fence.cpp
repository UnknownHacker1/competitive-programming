/*
 * Fence  [363B]
 * Problem:  https://codeforces.com/problemset/problem/363/B
 * Verdict:  ACCEPTED        Solved: 2021-01-02
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 2300 KB
 * Tags:     brute force, dp
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/363/submission/103021423
 */

#include <bits/stdc++.h>
using namespace std;
// Important functions and defines
typedef long long ll;
#define f first
#define s second
ll POW(ll a, ll b) {
   ll res = 1;
   while(b > 0) {
    if(b%2==1) res*=a;
    a*=a;
    b/=2;
   }
   return res;
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
    ll a[n+1];
    for(int i = 1; i <= n; i++) cin>>a[i];
    ll p[n+1] = {0};
    for(int i = 1; i <= n; i++) {
        p[i]=p[i-1]+a[i];
    }
    ll res = p[k];
    int ans = 1;
    for(int i = 0; i + k <= n; i++) {
        if(p[i+k]-p[i]<res) {
            res = p[i+k]-p[i];
            ans = i+1;
        }
    }
    cout<<ans;
    return 0;
}
