/*
 * Having Been a Treasurer in the Past, I Help Goblins Deceive  [2072B]
 * Problem:  https://codeforces.com/problemset/problem/2072/B
 * Verdict:  ACCEPTED        Solved: 2025-02-25
 * Language: C++17 (GCC 7-32)
 * Runtime:  77 ms     Memory: 0 KB
 * Tags:     combinatorics, constructive algorithms, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2072/submission/307688695
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
        int c0=0,c1=0;
        for(int i = 0; i < n; i++){
            char ch;
            cin>>ch;
            if(ch=='_')c0++;
            else c1++;
        }
        cout<<(c1/2)*1ll*c0*(c1-c1/2)<<'\n';
    }
	return 0;
}
