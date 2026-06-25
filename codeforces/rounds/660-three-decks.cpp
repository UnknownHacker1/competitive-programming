/*
 * Three Decks  [2104A]
 * Problem:  https://codeforces.com/problemset/problem/2104/A
 * Verdict:  ACCEPTED        Solved: 2025-08-21
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  46 ms     Memory: 100 KB
 * Tags:     math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2104/submission/334732809
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
        int a,b,c;
        cin>>a>>b>>c;
        c -= b-a;
        if(c >= b && (c-b) % 3 == 0) cout << "yes\n";
        else cout<<"no\n";
    }
    return 0;
}