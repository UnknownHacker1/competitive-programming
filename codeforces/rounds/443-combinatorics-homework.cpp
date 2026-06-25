/*
 * Combinatorics Homework  [1574B]
 * Problem:  https://codeforces.com/problemset/problem/1574/B
 * Verdict:  ACCEPTED        Solved: 2021-09-20
 * Language: C++17 (GCC 7-32)
 * Runtime:  30 ms     Memory: 3600 KB
 * Tags:     combinatorics, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1574/submission/129429197
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
 
ll gcd(ll a, ll b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}
#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end()
int main()
{
    ACPLS();
tc{
    int a,b,c,m;
    cin>>a>>b>>c>>m;
    if(max({a,b,c})-(a+b+c-max({a,b,c})+1)<=m&&m<=a-1+b-1+c-1)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
}
