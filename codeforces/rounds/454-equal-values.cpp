/*
 * Equal Values  [2111C]
 * Problem:  https://codeforces.com/problemset/problem/2111/C
 * Verdict:  ACCEPTED        Solved: 2025-08-29
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  140 ms     Memory: 200 KB
 * Tags:     brute force, greedy, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2111/submission/336074203
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
    while(t--){
        int n;
        cin>>n;
        ll a[n];
        for(auto&i:a)cin>>i;
        ll ans = (n-1)*a[0];
        for(int i = 0; i < n; ){
            int j = i;
            while(j + 1 < n && a[j + 1] == a[j]) ++j;
            ans=min(ans,(n-(j-i+1))*a[i]);
            i = j + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}