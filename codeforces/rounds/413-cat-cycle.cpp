/*
 * Cat Cycle  [1487B]
 * Problem:  https://codeforces.com/problemset/problem/1487/B
 * Verdict:  ACCEPTED        Solved: 2025-03-03
 * Language: C++17 (GCC 7-32)
 * Runtime:  46 ms     Memory: 100 KB
 * Tags:     math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1487/submission/308830330
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
        ll n,k;
        cin>>n>>k;
        if(n%2==0) {
            cout<<((k-1)%n) + 1<<'\n';
        } else { 

            cout<<( (k - 1 + (k - 1)/(n/2) ) % n)+1<<'\n';
        }
    }
	return 0;
}
