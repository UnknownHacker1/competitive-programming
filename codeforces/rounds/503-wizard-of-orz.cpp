/*
 * Wizard of Orz  [1467A]
 * Problem:  https://codeforces.com/problemset/problem/1467/A
 * Verdict:  ACCEPTED        Solved: 2021-01-08
 * Language: C++17 (GCC 7-32)
 * Runtime:  30 ms     Memory: 0 KB
 * Tags:     constructive algorithms, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1467/submission/103751113
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
int end;
vector<vector<int>> adj(2005);
vector<int> vis(2005, 0);

int32_t main()
{
    ///freopen ("output.txt","w",stdout);
    ///freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        cout<<9;
        --n;
        if(n>0) cout<<8;
        --n;
        if(n>0) cout<<9;
        --n;
        while(n>0) {
            for(int i = 0; i <= 9 && n > 0; i++) {
                cout<<i;
                --n;
            }
        }
        cout<<'\n';
    }
    return 0;
}
