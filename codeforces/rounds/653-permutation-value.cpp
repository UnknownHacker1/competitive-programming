/*
 * Permutation Value  [1743B]
 * Problem:  https://codeforces.com/problemset/problem/1743/B
 * Verdict:  ACCEPTED        Solved: 2024-02-27
 * Language: C++20 (GCC 11-64)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     constructive algorithms, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1743/submission/248476086
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n; 
        for(int i = 1; n - i + 1 > i; i++){
            cout<<i<<' '<<n - i + 1<<' '; 
        } 
        if(n & 1) cout<<(n + 1)/2;
        cout<<'\n';
    }
    return 0;
}