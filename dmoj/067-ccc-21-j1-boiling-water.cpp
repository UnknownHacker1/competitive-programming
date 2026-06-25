/*
 * CCC '21 J1 - Boiling Water  [ccc21j1]
 * Problem:  https://dmoj.ca/problem/ccc21j1
 * Verdict:  ACCEPTED (3.0 pts)   Solved: 2022-01-07
 * Language: C++20
 * Runtime:  0.017834723 s     Memory: 3328.0 KB
 * Source:   https://dmoj.ca/src/4186366
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
    while (tttttt--)99

#define sumrange(l, r, arr) (l == 0 ? arr[r] : arr[r] - arr[l - 1])
#define all(v) v.begin(), v.end() 
int main()
{
    ACPLS();
    int B;
    cin>>B;
    B=5*B-400;
    cout<<B<<'\n';
    if(B<100){
        cout<<1;
    }
    else if(B==100){
        cout<<0;
    }
    else cout<<-1;
}