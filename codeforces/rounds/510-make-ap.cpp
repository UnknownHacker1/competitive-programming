/*
 * Make AP  [1624B]
 * Problem:  https://codeforces.com/problemset/problem/1624/B
 * Verdict:  ACCEPTED        Solved: 2022-01-10
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1624/submission/142294225
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
    int a,b,c;
    cin>>a>>b>>c;
    if(( (2*b-a)%c==0 && (2*b-a)> 0 ) ||( (a+c)%(2*b)==0 )||( (2*b-c)%a==0 && (2*b-c) > 0 ) )
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
}
 
