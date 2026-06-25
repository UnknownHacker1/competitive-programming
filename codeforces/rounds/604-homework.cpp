/*
 * Homework  [2132A]
 * Problem:  https://codeforces.com/problemset/problem/2132/A
 * Verdict:  ACCEPTED        Solved: 2025-09-06
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  46 ms     Memory: 0 KB
 * Tags:     brute force, implementation, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/2132/submission/337084429
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 3;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a,b,c;
        cin>>a;
        int m;
        cin>>m;
        cin>>b>>c;
        for(int i = 0; i < m; i++){
            if(c[i]=='V'){
                string nw = {b[i]};
                nw+=a;
                a=nw;
            }else{
                a+=b[i];
            }
        }
        cout<<a<<'\n';
    }
    return 0;
}