/*
 * Expensive Number  [2093B]
 * Problem:  https://codeforces.com/problemset/problem/2093/B
 * Verdict:  ACCEPTED        Solved: 2025-04-29
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2093/submission/317748990
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
        string s;
        cin>>s;
        int n = (int)s.size();
        int cntz=0;
        int ans = n - 1;
        for(int i = 0; i < n; i++){
            if(s[i]!='0'){
                ans = min(ans, n - (cntz + 1));
            }
            else cntz++;
        }
        cout << ans << '\n';
    }
    return 0;
}