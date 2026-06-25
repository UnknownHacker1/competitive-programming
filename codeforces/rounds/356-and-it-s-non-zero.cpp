/*
 * And It's Non-Zero  [1615B]
 * Problem:  https://codeforces.com/problemset/problem/1615/B
 * Verdict:  ACCEPTED        Solved: 2021-12-25
 * Language: C++20 (GCC 11-64)
 * Runtime:  46 ms     Memory: 15600 KB
 * Tags:     bitmasks, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1615/submission/140573515
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
    int pre[(int)2e5+3][20];
    memset(pre,0,sizeof(pre));
    for(ll j = 0; j < 20; j++){
        for(ll i = 1; i <= 2e5; i++){
            if(i&(1<<j))
                pre[i][j]++;
            pre[i][j]+=pre[i-1][j];
        }
    }
tc{
    int l,r;
    cin>>l>>r;
    int x = 0;
    for(int i = 0; i < 20; i++){
        x=max(x,pre[r][i]-pre[l-1][i]);
    }
    cout<<r-l+1-x<<'\n';
}
}