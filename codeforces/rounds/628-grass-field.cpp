/*
 * Grass Field  [1701A]
 * Problem:  https://codeforces.com/problemset/problem/1701/A
 * Verdict:  ACCEPTED        Solved: 2025-03-10
 * Language: C++17 (GCC 7-32)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1701/submission/309743899
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
        int cntz=0;
        for(int i = 0; i < 4; i++){
            int d;
            cin>>d;
            cntz+=(d==0);
        }
        if(cntz==4)cout<<"0\n";
        else if(cntz>0)cout<<"1\n";
        else cout<<"2\n";
    }
    return 0;
}
