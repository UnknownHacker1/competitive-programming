/*
 * Not a Substring  [1860A]
 * Problem:  https://codeforces.com/problemset/problem/1860/A
 * Verdict:  ACCEPTED        Solved: 2025-03-10
 * Language: C++17 (GCC 7-32)
 * Runtime:  77 ms     Memory: 4200 KB
 * Tags:     constructive algorithms, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1860/submission/309880699
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
        string s;
        cin>>s;
        int n = (int)s.size();  
        string s1,s2;
        for(int i = 0; i < n; i++)s1.push_back('('),s2+="()";
        for(int i = 0; i < n; i++)s1.push_back(')');
        if(s1.find(s) == s1.npos){
            cout<<"YES\n";
            cout<<s1<<'\n';
        }else if(s2.find(s) == s2.npos) cout<<"YES\n"<<s2<<'\n';
        else cout<<"NO\n";
    }
    return 0;
}
