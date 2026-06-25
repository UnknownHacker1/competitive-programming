/*
 * GCD Arrays  [1629B]
 * Problem:  https://codeforces.com/problemset/problem/1629/B
 * Verdict:  ACCEPTED        Solved: 2022-01-22
 * Language: C++20 (GCC 11-64)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     greedy, math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1629/submission/143722045
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
int main()
{
    ACPLS();   
tc{
    int l,r,k;
    cin>>l>>r>>k;
    if(l==1&&r==1){
        cout<<"NO\n";
        continue;
    }
    if(l==r){
        cout<<"YES\n";
        continue;
    }
    int even = r/2-(l-1)/2;
    int odd = (r-l+1)-even;
    if(k>=odd){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
}
}