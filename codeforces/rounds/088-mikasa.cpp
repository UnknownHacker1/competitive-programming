/*
 * Mikasa  [1554C]
 * Problem:  https://codeforces.com/problemset/problem/1554/C
 * Verdict:  ACCEPTED        Solved: 2022-01-25
 * Language: C++20 (GCC 11-64)
 * Runtime:  30 ms     Memory: 0 KB
 * Tags:     binary search, bitmasks, greedy, implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1554/submission/143955446
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
    int n,m;
    cin>>n>>m;
    int ans=(1<<30)-n-1;
    for(int i = 29; i >= 0; i--){
        if(n&(1<<i))continue;
        if((n^(ans-(1<<i)))>m)
            ans-=(1<<i);
    }
    cout<<ans<<'\n';
}
}


