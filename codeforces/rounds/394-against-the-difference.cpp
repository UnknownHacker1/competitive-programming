/*
 * Against the Difference  [2136C]
 * Problem:  https://codeforces.com/problemset/problem/2136/C
 * Verdict:  ACCEPTED        Solved: 2025-10-17
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  218 ms     Memory: 18200 KB
 * Tags:     data structures, dp
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2136/submission/344406180
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;   

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);   

    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;

    int a[n+1];
    int f[n+1]{};
    map<int,int>pos[n+1];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ++f[a[i]];
        pos[a[i]][f[a[i]]] = i;
    }

    int mx[n+1];
    mx[0] = 0;
    memset(f,0,sizeof(f));

    int ans = 0;

    for(int i = 1; i <= n; i++){
        ++f[a[i]];
        mx[i] = mx[i - 1];
        if(f[a[i]] < a[i]) continue;

        int target = pos[a[i]][f[a[i]] - a[i] + 1];
        assert(target >= 1);
        assert(target <= i);
        ans = max(ans, mx[target - 1] + a[i]);
        mx[i] = max(ans, mx[i - 1]);

    }

    cout << ans << '\n';

    }
    return 0;
}