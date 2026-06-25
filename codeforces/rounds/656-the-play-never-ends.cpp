/*
 * The Play Never Ends  [2071A]
 * Problem:  https://codeforces.com/problemset/problem/2071/A
 * Verdict:  ACCEPTED        Solved: 2025-02-28
 * Language: C++17 (GCC 7-32)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2071/submission/308300359
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
        int k;
        cin>>k;
        if(k % 3 == 1) cout << "YES\n";
        else cout << "NO\n";
    }
	return 0;
}
