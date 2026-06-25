/*
 * Profitable Interest Rate  [2024A]
 * Problem:  https://codeforces.com/problemset/problem/2024/A
 * Verdict:  ACCEPTED        Solved: 2025-03-05
 * Language: C++17 (GCC 7-32)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     greedy, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2024/submission/309056928
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
        int a,b;
        cin>>a>>b;
        cout<<max(a-max(b-a,0),0)<<'\n';
    }
	return 0;
}
