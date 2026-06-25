/*
 * Coloring Game  [2112C]
 * Problem:  https://codeforces.com/problemset/problem/2112/C
 * Verdict:  ACCEPTED        Solved: 2025-08-31
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  483 ms     Memory: 0 KB
 * Tags:     binary search, brute force, greedy, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2112/submission/336330007
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 3;
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
        int a[n];
        for(auto&i:a)cin>>i;
        ll ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                // cnt of a[k] < a[i]+a[j] s.t. k in [j+1,n-1]
                // idx of first l, a[l] >= a[i]+a[j] - (j+1) - 1
                // j < k < l
                int idx = lower_bound(a + j + 1, a + n, a[i] + a[j]) - a;
                //cout<<i<<' '<<j<<' '<<idx<<' ';
                ll x = 0;
                x += max(0ll,(ll)idx - (j) - 1);
               
                // but there also can't exist any b > k such that a[b]>=a[i]+a[j]+a[k] 
                // so we gotta remove all k's tho such that a[n-1]>=a[k]+a[i]+a[j]
                //a[k]<=a[n-1]-a[i]-a[j] 
                idx = upper_bound(a + j + 1, a + n, a[n-1]-a[i]-a[j]) - a; 
                //cout<<idx<<' '<<max(0ll,(ll)idx - (j) - 1)<<'\n';
                x -= max(0ll,(ll)idx - (j) - 1);

                ans += max(0ll, x);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}