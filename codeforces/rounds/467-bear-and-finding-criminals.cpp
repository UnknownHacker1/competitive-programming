/*
 * Bear and Finding Criminals  [680B]
 * Problem:  https://codeforces.com/problemset/problem/680/B
 * Verdict:  ACCEPTED        Solved: 2020-12-23
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 0 KB
 * Tags:     constructive algorithms, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/680/submission/102142134
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
    int n, a;
    cin>>n>>a;
    bool t[n+1], notTaken[n+1];
    for(int i = 1; i <= n; i++) notTaken[i]=true;
    for(int i = 1; i <= n; i++) cin>>t[i];
    int res = 0;
    for(int i = 1; i <= n; i++) {
    if(t[i]) {

        if(i==a) {res+=notTaken[i], notTaken[i]=false;continue;}
        int distance = abs(a-i);
        if(a-distance>0&&a+distance>n) {
            res+=notTaken[a-distance];
            notTaken[a-distance]=false;
        } else if(a-distance<=0&&a+distance<=n) {
            res+=notTaken[a+distance];
            notTaken[a+distance]=false;
        }
        else if(a-distance>0&&a+distance<=n&&t[a-distance]&&t[a+distance]) {
            res+=notTaken[a+distance]+notTaken[a-distance];
            notTaken[a+distance]=false,notTaken[a-distance]=false;
        }

    }
    }
    cout<<res<<'\n';
    return 0;
}
