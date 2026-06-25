/*
 * New World, New Me, New Array  [2072A]
 * Problem:  https://codeforces.com/problemset/problem/2072/A
 * Verdict:  ACCEPTED        Solved: 2025-02-25
 * Language: C++17 (GCC 7-32)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     greedy, implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2072/submission/307678486
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
        int n,k,p;
        cin>>n>>k>>p;
        int ans = (abs(k) + p - 1)/p;
        if(ans > n) cout<<"-1\n";
        else cout<<ans<<'\n';
    }
	return 0;
}
