/*
 * Make Almost Equal With Mod  [1909B]
 * Problem:  https://codeforces.com/problemset/problem/1909/B
 * Verdict:  ACCEPTED        Solved: 2025-03-03
 * Language: C++17 (GCC 7-32)
 * Runtime:  77 ms     Memory: 100 KB
 * Tags:     bitmasks, constructive algorithms, math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1909/submission/308770808
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;  
uint64_t gcd(ll a, ll b){
    if(a == b) return a;
    return gcd(b, a % b);
}
int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    int t;
    cin>>t;
    while(t--){ 
        int n;
        cin>>n;
        ll a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        ll g = 0;
        for(int i = 1; i < n; i++){
            g = __gcd(g, abs(a[i] - a[i - 1]));
        }
        if(g == 0) ++g;
        cout << (g << 1) << '\n';
    }
	return 0;
}
