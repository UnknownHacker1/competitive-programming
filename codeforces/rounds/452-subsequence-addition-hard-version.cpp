/*
 * Subsequence Addition (Hard Version)  [1807G2]
 * Problem:  https://codeforces.com/problemset/problem/1807/G2
 * Verdict:  ACCEPTED        Solved: 2025-03-03
 * Language: C++17 (GCC 7-32)
 * Runtime:  108 ms     Memory: 100 KB
 * Tags:     bitmasks, dp, greedy, implementation, sortings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1807/submission/308769575
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;  

int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    int t;
    cin>>t;
    while(t--){ 
        int n;
        cin>>n;
        ll c[n];
        for(int i = 0; i < n; i++) cin >> c[i];
        sort(c,c+n);
        bool ok = 1;
        if(c[0] != 1){
            ok = 0;
        }
        for(int i = 1; i < n; i++){ 
            if(c[i] > c[i - 1]) ok = 0;
            c[i] += c[i - 1];
        }
        cout<<(ok?"YES\n":"NO\n");
    }
	return 0;
}
