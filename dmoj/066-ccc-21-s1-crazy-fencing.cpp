/*
 * CCC '21 S1 - Crazy Fencing  [ccc21s1]
 * Problem:  https://dmoj.ca/problem/ccc21s1
 * Verdict:  ACCEPTED (5.0 pts)   Solved: 2022-01-07
 * Language: C++20
 * Runtime:  0.026208535 s     Memory: 3580.0 KB
 * Source:   https://dmoj.ca/src/4186479
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
    int n;
    cin>>n;
    int h[n+1],w[n];
    for(auto&i:h)cin>>i;
    for(auto&i:w)cin>>i;
    double ans = 0;
    for(int i = 0; i < n; i++){
        ans+=w[i]*1.0*(h[i]+h[i+1]*1.0)/2.0;
    }
    cout<<fixed<<setprecision(6);
    cout<<ans;
}