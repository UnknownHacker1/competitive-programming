/*
 * Long Jumps  [1472C]
 * Problem:  https://codeforces.com/problemset/problem/1472/C
 * Verdict:  ACCEPTED        Solved: 2021-01-04
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 3100 KB
 * Tags:     dp, graphs
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1472/submission/103314268
 */

#include <bits/stdc++.h>
using namespace std;
// Important functions and defines
#define f first
#define s second
typedef long long ll;
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
int dist(int X1, int Y1, int X2, int Y2) {
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
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int MAX = 100005;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        ll a[n+1], sum[n+1];
        for(int i = 0; i < n; i++) cin>>a[i];
        for(int i = n-1; i >= 0; i--) {
            sum[i] = a[i];
            int j = a[i]+i;
            if(j<n)
                sum[i] += sum[j];
        }
        cout<<*max_element(sum, sum+n)<<'\n';
    }
    return 0;
}
