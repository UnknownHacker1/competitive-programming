/*
 * Love Triangle  [939A]
 * Problem:  https://codeforces.com/problemset/problem/939/A
 * Verdict:  ACCEPTED        Solved: 2020-12-06
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 0 KB
 * Tags:     graphs
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/939/submission/100582755
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
    int n;
    cin>>n;
    int love[n+1]={0};
    for(int i = 1; i <= n; i++) {
        int x;
        cin>>x;
        love[i] = x;
    }
    for(int i = 1; i <= n; i++) {
        if(love[love[love[i]]] == i) {
            cout << "YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
