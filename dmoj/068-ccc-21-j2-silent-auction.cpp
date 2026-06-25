/*
 * CCC '21 J2 - Silent Auction  [ccc21j2]
 * Problem:  https://dmoj.ca/problem/ccc21j2
 * Verdict:  ACCEPTED (3.0 pts)   Solved: 2022-01-07
 * Language: C++20
 * Runtime:  0.022684948 s     Memory: 3392.0 KB
 * Source:   https://dmoj.ca/src/4186373
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
    int n;
    cin>>n;
    string s[n];
    pair<int,int>mx={-1,-1};
    for(int i = 0; i < n; i++){
        int score;
        cin>>s[i]>>score;
        mx=max(mx,{score,-1*i});
    }
    cout<<s[-1*mx.second];
}