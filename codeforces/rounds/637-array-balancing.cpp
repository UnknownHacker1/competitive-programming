/*
 * Array Balancing  [1661A]
 * Problem:  https://codeforces.com/problemset/problem/1661/A
 * Verdict:  ACCEPTED        Solved: 2024-03-05
 * Language: C++20 (GCC 11-64)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1661/submission/249730529
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
        int a[n],b[n];
        for(auto&i:a)cin>>i;
        for(auto&i:b)cin>>i;
        ll ans = 0;
        for(int i = 0; i + 1 < n; i++){
            ans += abs(min(a[i + 1], b[i + 1]) - min(a[i], b[i])) + abs(max(a[i + 1], b[i + 1]) - max(a[i], b[i]));
        }
        cout<<ans<<'\n';
    }   
    return 0;
}