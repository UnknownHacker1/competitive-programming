/*
 * Strange Partition  [1471A]
 * Problem:  https://codeforces.com/problemset/problem/1471/A
 * Verdict:  ACCEPTED        Solved: 2021-01-05
 * Language: C++17 (GCC 7-32)
 * Runtime:  327 ms     Memory: 1700 KB
 * Tags:     greedy, math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1471/submission/103410211
 */

#include <bits/stdc++.h>
using namespace std;
// Important functions and defines
#define f first
#define s second
typedef long long ll;
ll POW(ll a, ll b) {
   ll res = 1;
   while(b > 0) {
    if(b%2==1) res*=a;
    a*=a;
    b/=2;
   }
   return res;
}
ll sum_range2d(ll i, ll j, ll k, ll l, vector<vector<ll>>& sum) {
    return sum[k][l] - sum[k][j - 1] - sum[i - 1][l] + sum[i - 1][j - 1];
}
ll gcd(ll a, ll b) {
    return (b == 0 ? abs(a) : gcd(b, a % b));
}
ll dist(ll X1, ll Y1, ll X2, ll Y2) {
    return sqrt( POW(X1-X2, 2) + POW(Y1-Y2,2) );
}
bool intersect(pair<int, int> p1, pair<int, int> p2) {
  int x1 = p1.first, x2 = p1.second, y1 = p2.first, y2 = p2.second;
  return (x1 >= y1 && x1 <= y2) ||
         (x2 >= y1 && x2 <= y2) ||
         (y1 >= x1 && y1 <= x2) ||
         (y2 >= x1 && y2 <= x2);
}
// End
int32_t main()
{
    ///ALWAYS REMEMBER TO USE REVERSE THINKING :)
    ///EXAMPLES: Think of solving a problem that has an array
    ///From the end to the beginning rather than from the beginning to the end
    ///And vice versa
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        double x;
        cin>>n>>x;
        double a[n];
        for(int i = 0; i < n; i++) cin>>a[i];
        vector<double> b(a, a+n);
        for(int i = 0; i < n-1; i++) {
            if( ceil(a[i]+a[i+1])/x > ceil((a[i]/x)+(a[i+1]/x)) ) {
                a[i+1] += a[i];
                a[i] = 0;
            }
            else if( ceil(b[i]+b[i+1])/x <= ceil((b[i]/x)+(b[i+1]/x)) ) {
                b[i+1] += b[i];
                b[i] = 0;
            }
        }
        ll result1 = 0, result2 = 0;
        for(int i = 0; i < n; i++) {
            result1+=ll(ceil(a[i]/x));
            result2+=ll(ceil(b[i]/x));
        }
        cout<<result2<<' '<<result1<<'\n';
    }
    return 0;
}
