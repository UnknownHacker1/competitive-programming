/*
 * Unique Bid Auction  [1454B]
 * Problem:  https://codeforces.com/problemset/problem/1454/B
 * Verdict:  ACCEPTED        Solved: 2020-11-24
 * Language: C++17 (GCC 7-32)
 * Runtime:  78 ms     Memory: 1600 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1454/submission/99466979
 */

#include <bits/stdc++.h>
using namespace std;
// Important functions and defines
typedef long long ll;
ll POW(ll expo, ll power) {
    ll res = expo; if (!power) return 1; while (--power) res *= expo; return res;
}
ll sum_range2d(int i, int j, int k, int l, vector<vector<ll>>& s) {
    return s[k][l] - s[k][j - 1] - s[i - 1][l] + s[i - 1][j - 1];
}
ll gcd(ll a, ll b) {
    return (b == 0 ? abs(a) : gcd(b, a % b));
}
// End
bool intersect(pair<int, int> p1, pair<int, int> p2) {
  int x1 = p1.first, x2 = p1.second, y1 = p2.first, y2 = p2.second;
  return (x1 >= y1 && x1 <= y2) ||
         (x2 >= y1 && x2 <= y2) ||
         (y1 >= x1 && y1 <= x2) ||
         (y2 >= x1 && y2 <= x2);
}
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int freq[n+1] = {0}, a[n];
        for(int i = 0; i < n; i++) {cin>>a[i];++freq[a[i]];}
        int min_num=INT_MAX;
        int min_index=-1;
        for(int i = 0; i < n; i++) {
            if(freq[a[i]]==1&&a[i]<min_num) {
                min_index = i+1, min_num=a[i];
            }
        }
        cout<<min_index<<'\n';
    }
    return 0;
}
