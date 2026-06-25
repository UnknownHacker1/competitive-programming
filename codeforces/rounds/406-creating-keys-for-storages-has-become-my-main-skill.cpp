/*
 * Creating Keys for StORages Has Become My Main Skill  [2072C]
 * Problem:  https://codeforces.com/problemset/problem/2072/C
 * Verdict:  ACCEPTED        Solved: 2025-02-25
 * Language: C++17 (GCC 7-32)
 * Runtime:  93 ms     Memory: 100 KB
 * Tags:     bitmasks, constructive algorithms, greedy
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2072/submission/307702232
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
        int n,x;
        cin>>n>>x;
        int i = 0;
        int cur = 0;
        for(; i < n; i++){
            if((i & x) != i || (i == n - 1 && (cur | i) != x)){
                break;
            }
            cout << i << ' ';
            cur |= i;
        }
        n -= i;
        while(n--) cout << x << ' ';
        cout<<'\n';
    }
	return 0;
}
