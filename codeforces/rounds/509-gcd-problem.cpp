/*
 * GCD Problem  [1617B]
 * Problem:  https://codeforces.com/problemset/problem/1617/B
 * Verdict:  ACCEPTED        Solved: 2021-12-17
 * Language: C++20 (GCC 11-64)
 * Runtime:  62 ms     Memory: 0 KB
 * Tags:     brute force, constructive algorithms, math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1617/submission/139628423
 */

/// isA AC
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void ACPLS()
{
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
#define tc         \
    int tttttt,subtask;    \
    cin >> tttttt /*>> subtask*/; \
    while (tttttt--)
#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end() 
ll sqr(ll x){
    return x*x;
}
int main()
{
    ACPLS(); 
tc{
    int n;
    cin>>n;
    int a = n-3, b = 2, c = 1;
    while(__gcd(a,b)!=1){
        --a;
        ++b;
    }
    cout<<a<<' '<<b<<' '<<c<<'\n';
}
}
