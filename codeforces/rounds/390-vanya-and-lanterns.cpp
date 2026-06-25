/*
 * Vanya and Lanterns  [492B]
 * Problem:  https://codeforces.com/problemset/problem/492/B
 * Verdict:  ACCEPTED        Solved: 2021-01-02
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 0 KB
 * Tags:     binary search, implementation, math, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/492/submission/103016962
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
    int n, l;
    cin>>n>>l;
    int a[n]={0};
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a+n);
    double ans = 0;
    for(int i = 0; i < n-1; i++) {
        ans=max(ans, double(abs(a[i+1]-a[i]))/2.0);
    }
    int MAX = a[n-1];
    int MIN = a[0];
    if(MIN != 0) {
        ans=max(ans, double(abs(MIN)));
    }
    if(MAX != l) {
        ans=max(ans, double(abs(l-MAX)));
    }
    cout<<fixed<<setprecision(10);
    cout<<ans;
    return 0;
}
