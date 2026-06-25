/*
 * Construct a Rectangle  [1622A]
 * Problem:  https://codeforces.com/problemset/problem/1622/A
 * Verdict:  ACCEPTED        Solved: 2024-04-21
 * Language: C++20 (GCC 13-64)
 * Runtime:  61 ms     Memory: 0 KB
 * Tags:     geometry, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1622/submission/257553538
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
        int a[3];
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        if(a[0] + a[1] == a[2] || (a[0] == a[1] && a[2] % 2 == 0) || (a[0] % 2 == 0 && a[1] == a[2])){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }    
}