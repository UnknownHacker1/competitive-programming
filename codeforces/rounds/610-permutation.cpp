/*
 * Permutation  [1701B]
 * Problem:  https://codeforces.com/problemset/problem/1701/B
 * Verdict:  ACCEPTED        Solved: 2025-03-10
 * Language: C++17 (GCC 7-32)
 * Runtime:  77 ms     Memory: 4100 KB
 * Tags:     greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1701/submission/309744782
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
        bool vis[n+1]{};
        cout<<"2\n";
        for(int i = 1; i <= n; i++){ 
            int x = i;
            while(x <= n && !vis[x]){
                vis[x] = 1;
                cout << x << ' ';
                x <<= 1;
            }
        }
        cout<<'\n';
    }
    return 0;
}
