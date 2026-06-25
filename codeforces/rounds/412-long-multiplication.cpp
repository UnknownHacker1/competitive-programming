/*
 * Long Multiplication  [1954C]
 * Problem:  https://codeforces.com/problemset/problem/1954/C
 * Verdict:  ACCEPTED        Solved: 2025-03-18
 * Language: C++17 (GCC 7-32)
 * Runtime:  62 ms     Memory: 100 KB
 * Tags:     greedy, math, number theory
 * Author:   BidoTeima
 * Source:   https://codeforces.com/contest/1954/submission/311332234
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
        string x,y;
        cin>>x>>y;
        bool equal=1;
        for(int i = 0; i < (int)x.size(); i++){
            if(equal&&x[i]!=y[i]){
                equal=0;
                if(x[i]<y[i])swap(x[i],y[i]);
                continue;
            }
            if(x[i]>y[i])swap(x[i],y[i]);
        }
        cout<<x<<'\n'<<y<<'\n';
    }
    return 0;
}