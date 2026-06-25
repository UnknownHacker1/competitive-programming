/*
 * Two Screens  [2025A]
 * Problem:  https://codeforces.com/problemset/problem/2025/A
 * Verdict:  ACCEPTED        Solved: 2025-03-11
 * Language: C++17 (GCC 7-32)
 * Runtime:  46 ms     Memory: 4100 KB
 * Tags:     binary search, greedy, strings, two pointers
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2025/submission/309956522
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;    

int main(){
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);  
    int q;
    cin>>q;
    while(q--){  
        string s,t;
        cin>>s>>t;
        int i;
        for(i = 0; i < min((int)s.size(),(int)t.size()) && s[i]==t[i]; i++);
        cout<<(int)s.size()+(int)t.size()-i+(i?1:0)<<'\n';
    }
    return 0;
}
