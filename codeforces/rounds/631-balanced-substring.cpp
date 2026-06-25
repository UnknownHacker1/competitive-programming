/*
 * Balanced Substring  [1569A]
 * Problem:  https://codeforces.com/problemset/problem/1569/A
 * Verdict:  ACCEPTED        Solved: 2024-03-12
 * Language: C++17 (GCC 7-32)
 * Runtime:  15 ms     Memory: 0 KB
 * Tags:     implementation
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1569/submission/250940343
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
        string s;
        cin>>n>>s;
        size_t x = s.find("ab");
        if(x == s.npos){
            x=s.find("ba");
            if(x==s.npos)cout<<"-1 -1\n";
            else cout<<x+1<<' '<<x+2<<'\n';
        }else{
            cout<<x+1<<' '<<x+2<<'\n';
        }
    }
    return 0;
}