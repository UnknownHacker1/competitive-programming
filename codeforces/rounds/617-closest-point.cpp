/*
 * Closest Point  [2004A]
 * Problem:  https://codeforces.com/problemset/problem/2004/A
 * Verdict:  ACCEPTED        Solved: 2025-03-04
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 0 KB
 * Tags:     implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2004/submission/308920490
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;   
int msb(int x){
    for(int i = 29; i >= 0; i--){
        if(x&(1<<i)) return i;
    }
}
int main(){
	
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
        if(n>2 || abs(a[0]-a[1]) == 1){
            cout<<"NO\n";
        }else cout<<"YES\n";
    }
	return 0;
}
