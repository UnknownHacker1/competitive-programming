/*
 * Sort the Array  [451B]
 * Problem:  https://codeforces.com/problemset/problem/451/B
 * Verdict:  ACCEPTED        Solved: 2021-01-04
 * Language: C++17 (GCC 7-32)
 * Runtime:  61 ms     Memory: 400 KB
 * Tags:     implementation, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/451/submission/103157432
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
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    bool f = false;
    pair<int, int> s={0,0};
    for(int i = 1; i < n; i++) {
        if(i<1) continue;
        if(a[i]<a[i-1]&&f==false) {
            s.first=i-1;
            s.second=i-1;
            while(a[i]<=a[i-1]&&i<n) {
                ++s.second;
                ++i;
            }
            reverse(a+s.first, a+i);
            f=true;
        }
    }
    for(int i = 0; i < n-1; i++) {
        if(a[i]>a[i+1]) {
            cout<<"no";
            return 0;
        }
    }
    cout<<"yes\n"<<s.f+1<<' '<<s.s+1;
    return 0;
}
