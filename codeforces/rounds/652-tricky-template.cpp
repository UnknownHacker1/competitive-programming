/*
 * Tricky Template  [1922A]
 * Problem:  https://codeforces.com/problemset/problem/1922/A
 * Verdict:  ACCEPTED        Solved: 2025-03-22
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  31 ms     Memory: 100 KB
 * Tags:     constructive algorithms, implementation, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1922/submission/311922130
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
int main()
{ 
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);  
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a,b,c;
        cin>>a>>b>>c;
        bool ok = 0;
        for(int i = 0; i < n; i++){
            if(c[i]!=a[i]&&c[i]!=b[i])ok=1; 
        }
        cout<<(ok?"YES\n":"NO\n");
    }
    return 0;
}