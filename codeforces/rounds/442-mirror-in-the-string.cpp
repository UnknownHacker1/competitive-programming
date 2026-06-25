/*
 * Mirror in the String  [1616B]
 * Problem:  https://codeforces.com/problemset/problem/1616/B
 * Verdict:  ACCEPTED        Solved: 2021-12-29
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 300 KB
 * Tags:     greedy, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1616/submission/141069900
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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int idx=1;
    while(idx<n&&s[idx]<=s[idx-1]&&s[idx]<s[0]){
        idx++;
    }
    for(int i = 0; i < idx; i++)
        cout<<s[i];
    for(int i = idx-1; i >= 0; i--)
        cout<<s[i];
    cout<<'\n';
}
}