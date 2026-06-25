/*
 * Mirrored Pairs  [a2]
 * Problem:  https://dmoj.ca/problem/a2
 * Verdict:  ACCEPTED (3.0 pts)   Solved: 2022-02-14
 * Language: C++20
 * Runtime:  0.009947213 s     Memory: 3416.0 KB
 * Source:   https://dmoj.ca/src/4338216
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
    string s;
    cout<<"Ready\n";
    while(getline(cin,s)){
        if(s.empty()||s[0]==' ')break; 
        sort(all(s));
        if((s[0]=='p'&&s[1]=='q')||(s[0]=='b'&&s[1]=='d'))
            cout<<"Mirrored pair\n";
        else cout<<"Ordinary pair\n";
    }
}