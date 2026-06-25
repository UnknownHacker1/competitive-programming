/*
 * Delete from the Left  [1005B]
 * Problem:  https://codeforces.com/problemset/problem/1005/B
 * Verdict:  ACCEPTED        Solved: 2021-01-02
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 700 KB
 * Tags:     brute force, implementation, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1005/submission/103044617
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
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    string s, t;
    cin>>s>>t;
    int i, j;
    int lastInvalidIndexI=0;
    int lastInvalidIndexJ=0;
    if(s.size()<t.size()) j=t.size()-s.size(), i = 0, lastInvalidIndexJ=j;
    else i = s.size()-t.size(), j = 0, lastInvalidIndexI=i;
    bool changed = false;
    for(;i<s.size();i++,j++) {
        if(s[i] != t[j]) lastInvalidIndexI=i, lastInvalidIndexJ=j, changed = true;
    }
    cout<<lastInvalidIndexI+lastInvalidIndexJ+(changed*2);
    return 0;
}
