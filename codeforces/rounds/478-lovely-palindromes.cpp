/*
 * Lovely Palindromes  [688B]
 * Problem:  https://codeforces.com/problemset/problem/688/B
 * Verdict:  ACCEPTED        Solved: 2021-01-04
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 300 KB
 * Tags:     constructive algorithms, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/688/submission/103156147
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
    string s;
    cin>>s;
    cout<<s;
    reverse(s.begin(), s.end());
    cout<<s;
    return 0;
}
