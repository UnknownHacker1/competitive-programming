/*
 * Points on Plane  [1809B]
 * Problem:  https://codeforces.com/problemset/problem/1809/B
 * Verdict:  ACCEPTED        Solved: 2024-03-01
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     binary search, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1809/submission/249213851
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
        ll n;
        cin>>n;
        cout<<ll(sqrtl(n-1))<<'\n'; 
    }
    return 0;
}