/*
 * DMOPC '21 Contest 6 P1 - Bigger Big Integer  [dmopc21c6p1]
 * Problem:  https://dmoj.ca/problem/dmopc21c6p1
 * Verdict:  ACCEPTED (3.0 pts)   Solved: 2022-02-18
 * Language: C++20
 * Runtime:  0.242247193 s     Memory: 4328.0 KB
 * Source:   https://dmoj.ca/src/4358384
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
    string s;
    cin>>n>>s;
    for(int i = 0; i+1 < (int)s.size(); i++){
        if(s[i]<s[i+1]){
            swap(s[i],s[i+1]);
            break;
        }
    }
    cout<<s;
}