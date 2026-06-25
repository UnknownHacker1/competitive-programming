/*
 * Summer sell-off  [810B]
 * Problem:  https://codeforces.com/problemset/problem/810/B
 * Verdict:  ACCEPTED        Solved: 2021-01-04
 * Language: C++17 (GCC 7-32)
 * Runtime:  93 ms     Memory: 4700 KB
 * Tags:     greedy, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/810/submission/103159930
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
ll sum_range2d(int i, int j, int k, int l, vector<vector<ll>>& sum) {
    return sum[k][l] - sum[k][j - 1] - sum[i - 1][l] + sum[i - 1][j - 1];
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
bool cmp(pair<ll, int>& p1, pair<ll, int>& p2) {
    return p1.f>p2.f;
}
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, f;
    cin>>n>>f;
    ll k[n], l[n];
    for(int i = 0; i < n; i++) cin>>k[i]>>l[i];
    vector<pair<ll, int>> choose;
    for(int i = 0; i < n; i++) {
        ll x=min(k[i]*2, l[i]),y=min(k[i], l[i]);
        if(x > y) {
            choose.push_back({x-y, i});
        }
    }
    sort(choose.begin(), choose.end(), cmp);
    for(int i = 0; i < f && i < (int)choose.size(); i++) {
        k[choose[i].s]*=2;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) ans+=min(k[i], l[i]);
    cout<<ans;
    return 0;
}
