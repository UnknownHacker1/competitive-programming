/*
 * Maximum Subsequence Value  [1365E]
 * Problem:  https://codeforces.com/problemset/problem/1365/E
 * Verdict:  ACCEPTED        Solved: 2024-03-20
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 0 KB
 * Tags:     brute force, constructive algorithms
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1365/submission/252431408
 */

#include <bits/stdc++.h> 
using namespace std; 
using ll = long long;     
const int N = 3e5 + 3; 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    int n;
    cin>>n;
    ll a[n];
    for(auto&i:a)cin>>i;
    if(n == 1){
        return cout<<a[0]<<'\n', 0;
    }
    if(n == 2){
        return cout<<(a[0]|a[1])<<'\n', 0;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                ans = max(ans, a[i] | a[j] | a[k]);
            }
        }
    }
    cout<<ans;
    return 0;
}