/*
 * Closest Cities  [1922C]
 * Problem:  https://codeforces.com/problemset/problem/1922/C
 * Verdict:  ACCEPTED        Solved: 2025-03-22
 * Language: C++23 (GCC 14-64, msys2)
 * Runtime:  109 ms     Memory: 100 KB
 * Tags:     greedy, implementation, math
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1922/submission/311927479
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
int main()
{ 
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);  
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n; 
        int a[n];
        ll b[n-1]{},c[n-1]{};
        for(auto&i:a)cin>>i; 
        b[0] = 1;
        //cout<<"1 ";
        for(int i = 1; i < n - 1; i++){
            b[i] = (a[i+1]-a[i]) < (a[i]-a[i-1]) ? 1 : a[i + 1] - a[i];
            b[i] += b[i - 1];
            //cout<<b[i]<<' ';
        }
        //cout<<'\n';
        c[n-2]=1;
        //cout<<"1 ";
        for(int i = n - 3; i >= 0; i--){
            c[i] = (a[i+1]-a[i]) < (a[i+2]-a[i+1]) ? 1 : a[i + 1] - a[i];
            c[i] += c[i+1];
            //cout<<c[i]<<' ';
        }
        //cout<<'\n';
        int q;
        cin>>q;
        while(q--){
            int x,y;
            cin>>x>>y;
            --x,--y;
            if(x<y)cout<<b[y-1]-(x==0?0:b[x-1])<<'\n';
            else{
                cout<<c[y]-(x==n-1?0:c[x])<<'\n';
            }
        }
    }
    return 0;
}