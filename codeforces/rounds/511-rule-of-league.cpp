/*
 * Rule of League  [1733B]
 * Problem:  https://codeforces.com/problemset/problem/1733/B
 * Verdict:  ACCEPTED        Solved: 2025-03-03
 * Language: C++17 (GCC 7-32)
 * Runtime:  77 ms     Memory: 0 KB
 * Tags:     constructive algorithms, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1733/submission/308768851
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
        int n,x,y;
        cin>>n>>x>>y;
        if(x>y) swap(x,y);
        --n;
        if(x != 0){
            cout<<"-1\n";
            continue;
        }
        if(y == 0 || n % y){
            cout<<"-1\n";
            continue;
        }
        for(int i = 1; i <= n; ){
            int j = i + y - 1;
            for(int k = i; k <= j; k++)cout<<i + 1<<' ';
            i=j + 1;
        }
        cout<<'\n';
    }
	return 0;
}
