/*
 * Two Towers  [1795A]
 * Problem:  https://codeforces.com/problemset/problem/1795/A
 * Verdict:  ACCEPTED        Solved: 2025-03-20
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  61 ms     Memory: 0 KB
 * Tags:     brute force, implementation, strings
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1795/submission/311526002
 */

 
#include <bits/stdc++.h>
using namespace std; 
using ll = long long;  

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){ 
        int n,m;
        cin>>n>>m;
        string a,b;
        cin>>a>>b;
        // find the place where a[i]==a[i-1]
        int inA=-1,inB=-1;
        for(int i = 1; i < n; i++){
            if(a[i]==a[i-1])inA=i;
        }
        for(int i = 1; i < m; i++){
            if(b[i]==b[i-1])inB=i;
        }
        if(inA != -1){
            while((int)a.size() > inA){
                b.push_back(a.back());
                a.pop_back(); 
            }
        }else if(inB != -1) {
            while((int)b.size() > inB){
                a.push_back(b.back());
                b.pop_back();
            }
        }
        bool ok = 1;
        for(int i = 1; i < (int)a.size(); i++) if(a[i]==a[i-1])ok=0;
        for(int i = 1; i < (int)b.size(); i++) if(b[i]==b[i-1])ok=0;
        cout<<(ok?"YES\n":"NO\n");
    }
    return 0;
}