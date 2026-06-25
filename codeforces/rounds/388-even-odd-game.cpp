/*
 * Even-Odd Game  [1472D]
 * Problem:  https://codeforces.com/problemset/problem/1472/D
 * Verdict:  ACCEPTED        Solved: 2021-01-04
 * Language: C++17 (GCC 7-32)
 * Runtime:  93 ms     Memory: 1600 KB
 * Tags:     dp, games, greedy, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1472/submission/103313356
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
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        ll a[n];
        for(int i = 0; i < n; i++) cin>>a[i];
        sort(a, a+n, greater<ll>());
        ll alice = 0, bob = 0;
        bool aliceturn = true;
        for(int i = 0; i < n; i++) {
            if(aliceturn) {if(a[i]%2==0) alice+=a[i];}
            else if(!aliceturn) {if(a[i]%2) bob+=a[i];}
            aliceturn=(!aliceturn);
        }
        if(alice>bob) cout<<"Alice\n";
        else if(bob>alice) cout<<"Bob\n";
        else cout<<"Tie\n";
    }
    return 0;
}
