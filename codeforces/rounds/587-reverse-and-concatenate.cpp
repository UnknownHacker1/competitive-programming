/*
 * Reverse and Concatenate  [1634A]
 * Problem:  https://codeforces.com/problemset/problem/1634/A
 * Verdict:  ACCEPTED        Solved: 2022-02-06
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     greedy, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1634/submission/145402643
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
    int n,k;
    string s;
    cin>>n>>k>>s;
    string rev=s;reverse(all(rev));
    if(rev==s){
        cout<<"1\n";
    }
    else cout<<min(k+1,2)<<'\n';
}
}


