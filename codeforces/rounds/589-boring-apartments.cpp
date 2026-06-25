/*
 * Boring Apartments  [1433A]
 * Problem:  https://codeforces.com/problemset/problem/1433/A
 * Verdict:  ACCEPTED        Solved: 2020-11-17
 * Language: C++17 (GCC 7-32)
 * Runtime:  31 ms     Memory: 0 KB
 * Tags:     implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1433/submission/98667516
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
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        int res = 0;
        int len = trunc(log10(n))+1;
        res+=(len*(len+1))/2;
        int ld = n%10;
        --ld;
        if(ld) {
            res+=ld*10;
        }
        cout<<res<<'\n';
    }
    return 0;
}
