/*
 * Beautiful Average  [2162A]
 * Problem:  https://codeforces.com/problemset/problem/2162/A
 * Verdict:  ACCEPTED        Solved: 2025-10-19
 * Language: C++20 (GCC 13-64)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     brute force, greedy
 * Author:   team "balls" (HossamIsmail, BidoTeima, a1abay)
 * Source:   https://codeforces.com/contest/2162/submission/344575734
 */

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int mx = 0;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        mx = max(mx,x);
    }
    cout << mx << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t=1;
    cin >> t;
    while(t--)
    solve();
    return 0;
}