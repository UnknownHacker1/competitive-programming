/*
 * Card Trick  [1681B]
 * Problem:  https://codeforces.com/problemset/problem/1681/B
 * Verdict:  ACCEPTED        Solved: 2025-03-19
 * Language: C++17 (GCC 7-32)
 * Runtime:  139 ms     Memory: 0 KB
 * Tags:     implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1681/submission/311394641
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
        int a[n];
        for(auto&i:a)cin>>i;
        int m,sm=0;
        cin>>m;
        for(int i = 0; i < m; i++){
            int x;
            cin>>x;
            sm=(sm+(n-x))%n;
        }
        cout<<a[(n-sm)%n]<<'\n';
    }
    return 0;
}