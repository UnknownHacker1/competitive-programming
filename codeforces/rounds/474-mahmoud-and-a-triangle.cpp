/*
 * Mahmoud and a Triangle  [766B]
 * Problem:  https://codeforces.com/problemset/problem/766/B
 * Verdict:  ACCEPTED        Solved: 2021-01-04
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 800 KB
 * Tags:     constructive algorithms, geometry, greedy, math, number theory, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/766/submission/103177125
 */

#include <bits/stdc++.h>
using namespace std;
// Important functions and defines
#define f first
#define s second
#define int long long
int POW(int a, int b) {
   int res = 1;
   while(b > 0) {
    if(b%2==1) res*=a;
    a*=a;
    b/=2;
   }
   return res;
}
int sum_range2d(int i, int j, int k, int l, vector<vector<int>>& sum) {
    return sum[k][l] - sum[k][j - 1] - sum[i - 1][l] + sum[i - 1][j - 1];
}
int gcd(int a, int b) {
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
int32_t main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a+n);
    for(int i = 0; i < n-2; i++) {
        if(a[i]+a[i+1]>a[i+2]) {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
