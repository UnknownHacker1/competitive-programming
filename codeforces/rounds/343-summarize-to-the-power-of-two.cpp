/*
 * Summarize to the Power of Two  [1005C]
 * Problem:  https://codeforces.com/problemset/problem/1005/C
 * Verdict:  ACCEPTED        Solved: 2021-01-22
 * Language: C++17 (GCC 7-32)
 * Runtime:  2511 ms     Memory: 151400 KB
 * Tags:     brute force, greedy, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1005/submission/105068449
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
    ll a[n];
    map<ll, int> freq{};
    for(int i = 0; i < n; i++) cin>>a[i], ++freq[a[i]];
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ///we need to check all 2^n from n = 1 to n = 31 (2 * 1e9)
        bool found = false;
        for(int p = 1; p <= 31; p++) {
            ll res = 1<<p;
            ll x, f;
            x=res-a[i], f=freq[res-a[i]];
            //cout<<"a[i]: "<<a[i]<<" x: "<<x<<" f: "<<f<<'\n';
            if(f > 0) {
                if(x==a[i] && f<2) continue;
                found=true;
                break;
            }
        }
        if(!found) ++ans;
    }
    cout<<ans;
    return 0;
}