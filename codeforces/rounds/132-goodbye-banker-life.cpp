/*
 * Goodbye, Banker Life  [2072F]
 * Problem:  https://codeforces.com/problemset/problem/2072/F
 * Verdict:  ACCEPTED        Solved: 2025-02-25
 * Language: C++17 (GCC 7-32)
 * Runtime:  327 ms     Memory: 100 KB
 * Tags:     2-sat, bitmasks, combinatorics, constructive algorithms, fft, math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2072/submission/307787361
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;  
ll lucas(ll n, ll r) {
    if (r > n) return 0;
    if (n < 2){
        return r < 2;
    }
    return (lucas(n >> 1, r >> 1) * lucas(n & 1, r & 1))&1;
}


int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i = 0; i < n; i++){
            cout<<(lucas(n - 1, i) ? k : 0)<<' ';
        }
        cout<<'\n';
    }
	return 0;
}
