/*
 * Binomial Coefficients, Kind Of  [2025B]
 * Problem:  https://codeforces.com/problemset/problem/2025/B
 * Verdict:  ACCEPTED        Solved: 2025-03-11
 * Language: C++17 (GCC 7-32)
 * Runtime:  109 ms     Memory: 4100 KB
 * Tags:     combinatorics, dp, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2025/submission/309958179
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;    
const int mod = 1e9 + 7, N=1e5+3;
int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);  
    int pw2[N];
    pw2[0]=1;
    for(int i = 1; i < N; i++) pw2[i] = ((pw2[i-1])<<1)%mod;
    int t;
    cin>>t;  
    int n[t],k[t];
    for(auto&i:n)cin>>i;
    for(auto&i:k){
        cin>>i;
        cout<<pw2[i]<<'\n';
    }
    return 0;
}
