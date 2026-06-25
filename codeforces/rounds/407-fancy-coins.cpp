/*
 * Fancy Coins  [1860B]
 * Problem:  https://codeforces.com/problemset/problem/1860/B
 * Verdict:  ACCEPTED        Solved: 2025-03-10
 * Language: C++17 (GCC 7-32)
 * Runtime:  93 ms     Memory: 4200 KB
 * Tags:     binary search, brute force, greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1860/submission/309882732
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
        int m,k,a1,ak;
        cin>>m>>k>>a1>>ak; 

        // minimize m % k + (m / k) 
        // minimize m % k 
        int mul = m % k; 
        int take1 = min(a1,mul);
        m -= take1;
        a1 -= take1;
        mul=k;
        m -= min((a1/mul)*mul, m);
        int take = min(ak,m/k);
        m-=take*k;
        cout<<(m%k)+(m/k)<<'\n';
    }
    return 0;
}
